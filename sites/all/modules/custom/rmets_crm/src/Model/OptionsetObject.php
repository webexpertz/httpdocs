<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;


class OptionsetObject {

  protected $key;
  protected $value;

  function __construct($item) {
    foreach ($item as $key => $value) {
      $this->key = $value;
      $this->value = $key;
    }
  }

  /**
   * @return mixed
   */
  public function getKey() {
    return $this->key;
  }

  /**
   * @param mixed $key
   */
  public function setKey($key) {
    $this->key = $key;
  }

  /**
   * @return mixed
   */
  public function getValue() {
    // Convert hexidec chars to real words.
    $words = explode('_', $this->value);
    $new_words = array();
    foreach ($words as $word) {
      if (isset($word[0]) && drupal_strtolower($word[0]) == 'x' && strlen($word) == 5) {
        $word = chr(hexdec(substr($word, 1)));
      }
      $new_words[] = $word;
    }
    return implode('', $new_words);
  }

  /**
   * @param mixed $value
   */
  public function setValue($value) {
    $this->value = $value;
  }

}