<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Driver;

use Drupal\rmets_crm\Api\ApiClientException;
use GuzzleHttp\Exception\BadResponseException;
/**
 *
 */
class MsDynamics extends AbstractGuzzleDriver {

  protected $secret;
  protected $base_url;

  public function __construct($conf) {
    $this->logFile = 'rmets-crm-requests-' . date('Y-m-d') . '.log';
    $this->exceptionLogFile = 'rmets-crm-exceptions-' . date('Y-m-d') . '.log';

    if (empty($conf['base_url'])) {
      throw new ApiClientException('The CRM MsDynamics driver requires a valid endpoint');
    }
    $this->base_url = $conf['base_url'];

    if (!empty($conf['cache_bin'])) {
      $this->setCacheBin($conf['cache_bin']);
    }

    if (!empty($conf['log_type'])) {
      $this->logType = $conf['log_type'];
    }

    if (!empty($conf['log_path'])) {
      $this->logPath = $conf['log_path'];
    }

    parent::__construct($conf);
  }

  public function getGuzzleOptions() {
    $options = parent::getGuzzleOptions();
    $options['base_url'] = $this->base_url;
    return $options;
  }

  public function decodeError(BadResponseException $ex) {
    // Just in case something went so wrong that there wasn't even a properly
    // formed error message...
    if ($ex->getResponse()->getHeader('Content-Type') == 'application/json') {
      $error = $ex->getResponse()->json();
      return $error['message'] . '. ' . parent::decodeError($ex);
    }
    return parent::decodeError($ex);
  }

}
