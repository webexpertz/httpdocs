<?php
/**
 * @file
 * Created by PhpStorm.
 * User: danj
 * Date: 13/03/15
 * Time: 11:48.
 */

namespace Drupal\rmets_crm\Api;

/**
 * Thrown when something goes wrong that's outside of our control. Almost
 * certainly these exceptions link back to HTTP 5xx errors.
 */
class ApiServerException extends ApiException {

}
