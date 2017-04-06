<?php

/**
 * @file
 * event_type taxonomy term wrapper class.
 */

namespace Drupal\rmets_wrapper\EntityWrapper\TaxonomyTerm;
use Drupal\rmets_membership_user\EntityWrapper\User\UserWrapper;

/**
 * Wraps event_type taxonomy terms.
 */
class AccreditationTypeTermWrapper extends TaxonomyTermWrapper {

  /**
   * @param int|object $data
   *   A tid or taxonomy_term object.
   *
   * @return AccreditationTypeTermWrapper
   */
  public static function GetObject($data) {
    return new AccreditationTypeTermWrapper($data);
  }

  /**
   * {@InheritDoc}
   */
  public static function getTaxonomyMachineName() {
    return 'accreditation_type';
  }

  /**
   * Get by the CRM Accreditation ID
   *
   * @param $crm_id
   * @return \Drupal\rmets_wrapper\EntityWrapper\TaxonomyTerm\AccreditationTypeTermWrapper
   */
  public static function getByCrmAccreditationId($crm_id) {
    $tid = db_query("
      SELECT entity_id FROM {field_data_field_crm_accreditation_field}
      WHERE bundle='accreditation_type' AND field_crm_accreditation_field_value=:id",
      [':id' => $crm_id])->fetchField();
    return new AccreditationTypeTermWrapper($tid);
  }

  /**
   * @param UserWrapper $account_wrapper
   * @param $crm_id
   */
  public static function getByCrmAccreditationItemId($account_wrapper, $crm_id) {
    $accreditations = $account_wrapper->getMembershipPackageAccreditations();
    foreach ($accreditations AS $accreditation) {
      /** @var $accreditation \Drupal\rmets_crm\Model\AccreditationItem */
      if ($accreditation->getAccreditationItemID() == $crm_id) {
        return AccreditationTypeTermWrapper::getByCrmAccreditationId($accreditation->getAccreditationID());
      }
    }
  }

  /**
   * @return string
   * @throws \EntityMetadataWrapperException
   */
  public function getRenewalFrequency() {
    return $this->getField('field_accreditation_renewal_freq');
  }
}
