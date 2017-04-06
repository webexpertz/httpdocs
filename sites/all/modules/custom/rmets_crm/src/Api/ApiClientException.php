<?php
/**
 * @file
 * Created by PhpStorm.
 * User: danj
 * Date: 13/03/15
 * Time: 11:50.
 */

namespace Drupal\rmets_crm\Api;

/**
 * Thrown when something goes wrong that's probably within our control. Almost
 * certainly these exceptions link back to HTTP 4xx errors.
 *
 * Whilst these errors should certainly increment the error counter and
 * eventually turn the CRM off, they shouldn't be caught because they indicate
 * a problem with our code that needs to be fixed.
 */
class ApiClientException extends ApiException {

}
