<?php
/**
 * @file
 * Firm Profile wrapper class.
 */

namespace Drupal\rmets_membership_purchase\EntityWrapper\CommerceProduct;

use \EntityDrupalWrapper;
use Drupal\rmets_crm\Api\Request\GetAllMembershipPackagePricesRequest;
use Drupal\rmets_crm\Api\Request\GetMembershipPackageJournalsRequest;


/**
 * Wraps nodes of type firm_profile with additional functionality.
 */
class CommerceProductWrapper extends EntityDrupalWrapper {

  protected $membership_packages;

  /**
   * Wrap a user object.
   *
   * @param int|object $data
   *   A uid or user object.
   */
  public function __construct($data) {
    parent::__construct('commerce_product', $data);
  }

  public function getMembershipPackageIdFromId($id) {
    if (empty($this->membership_packages)) {
      $this->membership_packages = $this->getAllMembershipPackagePrices();
    }
    $membership_packages = $this->membership_packages;
    foreach ($membership_packages AS $package) {
      if ($package->getMembershipPackagePriceID() == $id) {
        return $package->getPackageId();
      }
    }
  }

  public function getAllMembershipPackagePrices() {
    try {
      $request = new GetAllMembershipPackagePricesRequest();

      $request->setGuid(variable_get('rmets_crm_api_guid', ''));
      $request->setPage(1);
      $request->setRecordCount(100);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $this->membership_packages = $api->getAllMembershipPackagePrices($request);
      return $this->membership_packages;
    }
    catch (InvalidRequestException $e) {
      print drupal_set_message($e->getMessage(), 'error');
    }
    catch (ApiServerException $apie) {
      print drupal_set_message($apie->getMessage(), 'error');
    }
  }

  public function getAllMembershipPackageJournals($package_id) {
    try {
      $request = new GetMembershipPackageJournalsRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));
      $request->setPackageId($package_id);
      $request->setPage(1);
      $request->setRecordCount(100);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getMembershipPackageJournals($request);
      return $response;
    }
    catch (InvalidRequestException $e) {
      print drupal_set_message($e->getMessage(), 'error');
    }
    catch (ApiServerException $apie) {
      print drupal_set_message($apie->getMessage(), 'error');
    }
  }
}
