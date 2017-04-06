<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
abstract class AbstractPostRequest extends AbstractRequest implements RequestPostInterface {

  public function validate() {
    return array();
  }

  public function getHttpPostRequestBody() {
    $entities = new \stdClass();
    foreach ($this->params as $key => $value) {
      // Remove the guid for the time being as it is not needed.
      if ($key == 'guid') {
        continue;
      }
      $member = ucfirst($key);
      $entities->$member = $value;
    }

    $data = new \stdClass();
    $data->Entities[0] = $entities;

    return $data;
  }

  public function isCacheable() {
    return FALSE;
  }

}
