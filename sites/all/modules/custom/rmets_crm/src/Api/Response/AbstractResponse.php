<?php

/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;


use ArrayIterator;
use Drupal\rmets_crm\Api\Request\InvalidRequestException;
use IteratorAggregate;

/**
 * Provides functionality for responses from the API that have paged output.
 *
 * @package Drupal\rmets_crm\Api\Response
 */
abstract class AbstractResponse implements ResponseInterface, IteratorAggregate {

  protected $failureReason = NULL;
  protected $moreRecords;
  protected $entityName;
  protected $optionSetName;
  protected $items;
  protected $id;

  /**
   * @param array $raw_response
   *   The raw json returned from the API.
   *   Individual items will be found by implementing classes.
   */
  public function __construct(array $raw_response) {
    /*print "RAW:";
    print_r($raw_response);*/
    //die();
    if ($this->isGetResponse($raw_response)) {
      $this->processGetResponse($raw_response);
    }
    else {
      $this->processSetResponse($raw_response);
    }
  }

  /**
   * Allow looping over the returned items.
   *
   * @return \ArrayIterator
   */
  public function getIterator() {
    if (empty($this->items)) {
      $this->items = array();
    }
    return new ArrayIterator($this->items);
  }

  /**
   * @return mixed
   */
  public function getMoreRecords() {
    return $this->moreRecords;
  }

  /**
   * @return mixed
   */
  public function getId() {
    return $this->id;
  }

  /**
   * Convert a list of items into models.
   *
   * @param array $items
   *
   * @return object[]
   */
  abstract protected function buildItems(array $items);

  /**
   * Returns TRUE if this response matches what is expected from a Get request.
   *
   * @param $raw_response
   *
   * @return bool
   */
  protected function isGetResponse($raw_response) {
    return isset($raw_response['GetJsonResult']);
  }

  /**
   * Process the response from the GET request.
   *
   * @param $raw_response
   *
   * @throws \Drupal\rmets_crm\Api\Request\InvalidRequestException
   */
  protected function processGetResponse($raw_response) {
    $this->moreRecords = (bool) $raw_response['GetJsonResult']['MoreRecords'];
    $this->entityName = (string) $raw_response['GetJsonResult']['EntityName'];
    $this->optionSetName = (string) $raw_response['GetJsonResult']['OptionSetName'];

    if (!$raw_response['GetJsonResult']['Success']) {
      $this->failureReason = $raw_response['GetJsonResult']['FailureReason'];
      throw new InvalidRequestException($this->failureReason);
    }
    else {
      $data = array();
      if (!is_null($raw_response['GetJsonResult']['Entities'])) {
        $data = $raw_response['GetJsonResult']['Entities'];
      }
      if (!is_null($raw_response['GetJsonResult']['OptionSets'])) {
        $data = $raw_response['GetJsonResult']['OptionSets'];
      }
      $this->items = $this->buildItems($data);
    }
  }

  /**
   * Process the response from the POST request.
   *
   * @param $raw_response
   *
   * @throws \Drupal\rmets_crm\Api\Request\InvalidRequestException
   */
  protected function processSetResponse($raw_response) {
    if (!$raw_response['Success']) {
      $this->failureReason = $raw_response['FailureReason'];
      throw new InvalidRequestException($this->failureReason);
    }
    else {
      if (isset($raw_response['ID'])) {
        $this->id = $raw_response['ID'];
      }
      if (is_array($raw_response['CreatedEntities'])) {
        $this->items = $this->buildItems($raw_response['CreatedEntities']);
      }
    }
  }

}
