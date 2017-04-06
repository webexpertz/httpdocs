<?php
/**
 * @file
 * Created by PhpStorm.
 * User: danj
 * Date: 13/03/15
 * Time: 11:49.
 */

namespace Drupal\rmets_crm\Api;


use Exception;
use WSIFUnavailableException;

/**
 * All ApiExceptions within the application extend WSIF to ensure proper
 * logging.
 */
abstract class ApiException extends WSIFUnavailableException {

  public function __construct($message = '', $increment_fault_counter = TRUE, Exception $previous = NULL) {

    parent::__construct(CrmService::WSIF_API_NAME, $message, $increment_fault_counter, $previous);

    // To avoid double logging exceptions generated when the API is unavailable
    // only log when the fault counter hasn't yet been incremented.
    // Do this after the initial construction so that watchdog_exception can
    // read all applicable parameters.
    if ($increment_fault_counter) {
      watchdog_exception('rmets_crm', $this);
    }
  }

}
