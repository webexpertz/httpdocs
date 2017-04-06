<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

class AbstractModel {

  function __construct(array $item) {
    foreach ($item as $key => $value) {
      $member = lcfirst($key);
      $this->$member = $value;
    }
  }

}