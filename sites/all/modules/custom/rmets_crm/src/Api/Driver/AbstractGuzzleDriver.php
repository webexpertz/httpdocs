<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Driver;

use Drupal\rmets_crm\Api\ApiClientException;
use Drupal\rmets_crm\Api\ApiServerException;
use Drupal\rmets_crm\Api\Request\InvalidRequestException;
use Drupal\rmets_crm\Api\Request\RequestInterface;
use Drupal\rmets_crm\Api\Request\RequestPostInterface;
use GuzzleHttp\Client;
use GuzzleHttp\Exception\BadResponseException;
use GuzzleHttp\Exception\ClientException;
use GuzzleHttp\Exception\ServerException;

/**
 *
 */
abstract class AbstractGuzzleDriver implements DriverInterface {

  const LOG_TYPE_DISABLED = 0;
  const LOG_TYPE_DISPLAY = 1;
  const LOG_TYPE_LOG_FILE = 2;

  protected $client;
  protected $cache_bin;
  protected $logPath = '/';
  protected $logType = self::LOG_TYPE_DISABLED;
  protected $logFile = 'request.log';
  protected $exceptionLogFile = 'exception.log';

  public function __construct($conf) {
    $this->client = new Client($this->getGuzzleOptions());
  }

  /**
   * @param mixed $cache_bin
   */
  public function setCacheBin($cache_bin) {
    $this->cache_bin = $cache_bin;
  }

  public function getGuzzleOptions() {
    return array();
  }

  public function get($endpoint, RequestInterface $request = NULL) {
    $options = array();
    if ($request) {
      if ($errors = $request->validate()) {
        throw new InvalidRequestException('Invalid request to "' . $endpoint . '". ' . implode(' ', $errors));
      }
      $options['query'] = $request->getParams();
      // The guid is not needed anymore for this integration, so initially removed
      // it from here.
      unset($options['query']['guid']);
    }

    $cache = $request->isCacheable();
    $cache_key = $this->getCacheKey($endpoint, $request);
    if (!$cache || ($result = $this->getCachedResult($cache_key)) === FALSE) {
      try {
        $response = $this->client->get('Get?cmd=' . $endpoint, $options);
        $result = $response->json();
        if ($cache) {
          $this->setCachedResult($cache_key, $result, $request->getCacheLifetime());
        }
      }
      catch (ClientException $ex) {
        // If you need to debug exceptions then you can do so nicely by
        // (string) $ex->getRequest() and (string) $ex->getResponse()
        $this->logException($endpoint, $options, $this->decodeError($ex));
        throw new ApiServerException($this->decodeError($ex), TRUE, $ex);
      }
      catch (ServerException $ex) {
        // Same here.
        $this->logException($endpoint, $options, $this->decodeError($ex));
        throw new ApiServerException($this->decodeError($ex), TRUE, $ex);
      }
    }

    $this->logRequest($endpoint, $options, !isset($response), $result);

    return $result;
  }

  public function post($endpoint, RequestPostInterface $request = NULL) {
    $options = array();
    if ($request) {
      if ($errors = $request->validate()) {
        throw new InvalidRequestException('Invalid request to "' . $endpoint . '". ' . implode(' ', $errors));
      }
      // The guid is not needed anymore for this integration.
      //$options['query'] = array('guid' => $request->getParam('guid'));
    }

    try {
      $data = $request->getHttpPostRequestBody();
      //printf("Data: %s\n", json_encode($data));
      $options['body'] = json_encode($data);
      $response = $this->client->post('Set?cmd=' . $endpoint, $options);
      $result = $response->json();
    }
    catch (ClientException $ex) {
      // If you need to debug exceptions then you can do so nicely by
      // (string) $ex->getRequest() and (string) $ex->getResponse()
      $this->logException($endpoint, $options, $this->decodeError($ex));
      throw new ApiServerException($this->decodeError($ex), TRUE, $ex);
    }
    catch (ServerException $ex) {
      // Same here.
      $this->logException($endpoint, $options, $this->decodeError($ex));
      throw new ApiServerException($this->decodeError($ex), TRUE, $ex);
    }

    $this->logRequest($endpoint, $options, FALSE, $result);

    return $result;
  }

  /**
   * Attempt to retrieve a result from the cache.
   *
   * @param string $cache_key
   *   Generated with self::getCacheKey()
   *
   * @return bool
   */
  public function getCachedResult($cache_key) {
    $cache = cache_get($cache_key, $this->cache_bin);
    if ($cache != FALSE && $cache->expire > REQUEST_TIME) {
      return $cache->data;
    }
    return FALSE;
  }

  /**
   * Store an API response in the cache.
   *
   * @param string $cache_key
   *
   * @param mixed $response
   * @param int $cache_lifetime
   */
  public function setCachedResult($cache_key, $response, $cache_lifetime = 3600) {
    if ($cache_lifetime > 0) {
      cache_set($cache_key, $response, $this->cache_bin, REQUEST_TIME + $cache_lifetime);
    }
  }

  /**
   * Generate a unique cache key.
   *
   * @param $endpoint
   * @param \Drupal\rmets_crm\Api\Request\RequestInterface $request
   *
   * @return string
   */
  public function getCacheKey($endpoint, RequestInterface $request) {
    $params = $request->getParams();
    $params['endpoint'] = $endpoint;
    // Using old-school sha1 because of low probablity of collision and lack of
    // need for security.
    $param_string = sha1(implode(array_values($params), ':'));
    return $param_string;
  }

  /**
   * Provide efficient exception reporting.
   *
   * @param \GuzzleHttp\Exception\BadResponseException $ex
   *
   * @return string
   */
  public function decodeError(BadResponseException $ex) {
    return $ex->getMessage();
  }

  /**
   * Determine if and how to log API requests.
   *
   * @param $endpoint
   * @param $options
   * @param $cached
   * @param $response
   */
  public function logRequest($endpoint, $options, $cached, $response) {
    if (!$this->logType) {
      return;
    }

    $log_data = array(
      'request' => array($endpoint, $options),
      'response' => $response,
      'cache' => $cached ? 'hit' : 'miss',
      // Have to re-encode for the purposes of cache hits.
      'raw_response' => json_encode($response),
    );
    $this->log($endpoint, $log_data);
  }

  /**
   * Logs exception messages to a separate log file.
   *
   * @param $endpoint
   * @param $options
   * @param $exception_message
   */
  public function logException($endpoint, $options, $exception_message) {
    if (!$this->logType) {
      return;
    }

    $log_data = array(
      'request' => array($endpoint, $options),
      'exception' => $exception_message,
    );
    $this->log($endpoint, $log_data, TRUE);
  }

  /**
   * Function for logging the message depending upon the log type.
   *
   * @param $endpoint
   * @param $log_data
   * @param bool $exception\
   */
  protected function log($endpoint, $log_data, $exception = FALSE) {
    if ($this->logType == self::LOG_TYPE_DISPLAY) {
      $log_display_function = (function_exists('dpm')) ? 'dsm' : 'print_r';
      $log_display_function($log_data);
    }
    if ($this->logType == self::LOG_TYPE_LOG_FILE) {
      $log_info = date('Y-m-d H:i:s') . ": Request to: $endpoint\n" . print_r($log_data, TRUE);
      $log_file = ($exception) ? $this->exceptionLogFile : $this->logFile;
      file_put_contents(DRUPAL_ROOT . '/' . $this->logPath . $log_file, $log_info, FILE_APPEND);
    }
  }

}
