<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Driver;

use Drupal\rmets_crm\Api\Driver\Mock\UnsupportedEndpontException;
use Drupal\rmets_crm\Api\Request\PagedRequestInterface;
use Drupal\rmets_crm\Api\Request\RequestInterface;
use GuzzleHttp\Message\Response;
use GuzzleHttp\Stream\Stream;
use GuzzleHttp\Subscriber\Mock as GuzzleMock;
/**
 *
 */
class Mock extends AbstractGuzzleDriver {

  protected $mock;

  public function getResponsesDir() {
    return drupal_get_path('module', 'rmets_crm') . '/mock_responses';
  }

  public function get($endpoint, RequestInterface $request = NULL) {
    if ($request instanceof PagedRequestInterface) {
      $page = $request->getParam('page', 1);
      $file = $this->getResponsesDir() . '/' . trim($endpoint, '/') . '--page' . $page . '.json';
    }
    else {
      $file = $this->getResponsesDir() . '/' . trim($endpoint, '/') . '.json';
    }

    if (!file_exists($file)) {
      throw new UnsupportedEndpontException('Cannot find a mock file ' . $file);
    }

    $handle = fopen($file, 'r');

    $this->getMock()->addResponse(new Response(200, array('rmets_crm-mock-response' => 1), Stream::factory($handle)));

    $response = parent::get($endpoint, $request);
    /*if ($cache_lifetime > 0) {
      $this->setCachedResult($cache_key, $response, $cache_lifetime);
    }*/

    return $response;
  }

  /**
   * @return \GuzzleHttp\Subscriber\Mock
   */
  public function getMock() {
    if (!isset($this->mock)) {
      $this->setMock(new GuzzleMock());
    }

    return $this->mock;
  }

  /**
   * @param mixed $mock
   */
  public function setMock(GuzzleMock $mock) {
    $this->mock = $mock;
    $this->client->getEmitter()->attach($mock);
  }

}
