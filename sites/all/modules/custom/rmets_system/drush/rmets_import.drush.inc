<?php

/**
 * @file
 * Drush import scripts for the rmets project
 */

/**
 * Implements hook_drush_import_info().
 *
 * @return array
 *   Keyed by the import type ID. Must be lower case, no spaces
 *   e.g. my_content
 *   This is used to determine two callback functions:
 *   ID_get_data() (e.g. my_content_get_data() )
 *   ID_save_node() (e.g. my_content_save_node() )
 *   Values are sub-arrays with the following keys:
 *     'key' => The name of the unique id field.
 */
function rmets_system_drush_import_info() {
  return array(
    'rmets_corporate_member' => array(
      'key' => 'cm_ID',
    ),
    'cmet_member_records' => array(
      'key' => 'cmet_ID',
    ),
    'committee_documents' => array(
      'key' => 'doc_ID',
    ),
    'image_gallery' => array(
      'key' => 'img_ID',
    ),
    'news' => array(
      'key' => 'nw_ID',
    ),
    'events' => array(
      'key' => 'ev_ID',
    ),
    'awards' => array(
      'key' => 'nid',
    ),
    'event_abstracts' => array(
      'key' => 'abs_ID',
    ),
  );
}

/**
 * Implements ID_get_data().
 * Get data handler for the event abstracts.
 *
 * @return array
 *   An array of objects, each object should be the basis of later
 *   creating a node using the other callback function _name_save_node.
 */
function committee_documents_get_data() {
  db_set_active('oldwebsite');
  $out = db_query("SET CHARACTER SET UTF8;");
  $out = db_query("SELECT * FROM rmetsdev_old_website_2.documents");
  db_set_active();
  return $out;
}

/**
 * Implements ID_save_node().
 * Save node handler for event abstracts.
 * out of accreditation_awards nodes and into award_profile
 *
 * @param object $record
 *   A record object. This is one of the items in the array returned
 *   by the _name_get_data callback function.
 * @param object $existing_node
 *   The node to update with this record if there is one.
 *
 * @return object|boolean
 *   The new or updated node or FALSE if nothing was saved.
 */
function committee_documents_save_node($record, $existing_node = NULL) {
  // Defien relationship between ow_ID and the committees.
  static $committees = array(
    24 => array('title' => 'Council', 'tid' => 14 ),
    25 => array('title' => 'Meetings Committee', 'tid' => 15 ),
    35 => array('title' => 'Editorial Board - Meteorological Applications', 'tid' => 18 ),
    37 => array('title' => 'Editorial Board - The Quarterly Journal', 'tid' => 19 ),
    39 => array('title' => 'Accreditation Board', 'tid' => 51 ),
    40 => array('title' => 'Awards Committee', 'tid' => 52 ),
    41 => array('title' => 'Education Committee', 'tid' => 54 ),
    42 => array('title' => 'House Committee', 'tid' => 55 ),
    43 => array('title' => 'Publishing Committee', 'tid' => 56 ),
    45 => array('title' => 'Sector Committee', 'tid' => 57 ),
    44 => array('title' => 'Strategic Programme Committee', 'tid' => 58 ),
  );

  $meeting_timestamp = strtotime($record->doc_meetingdate);
  if (empty($meeting_timestamp)) {
    drupal_set_error('Problem with meeting timestamp ' . $record->doc_ID);
    return FALSE;
  }

  // Find or create meeting.
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'committee_meeting')
    ->fieldCondition('field_committee', 'tid', $committees[$record->ow_ID]['tid'], '=')
    ->fieldCondition('field_meeting_date', 'value', $record->doc_meetingdate, '=')
    ->execute();

  $meeting = new stdClass();
  if (isset($result['node'])) {
    $meeting = node_load(reset(array_keys($result['node'])));
  }
  else {
    // Create the meeting.
    $meeting->type = 'committee_meeting';
    $meeting->title = $committees[$record->ow_ID]['title'] . ' ' . date('d-m-Y', $meeting_timestamp);
    $meeting->uid = 1;
    $meeting->log = t('Imported committee meeting from old system based on document with doc_ID @id', array('@id' => $record->doc_ID));
    $meeting->status = TRUE;
    $meeting->language = LANGUAGE_NONE;
    node_save($meeting);

    $meeting_wrapper = entity_metadata_wrapper('node', $meeting);
    $meeting_wrapper->field_committee->set($committees[$record->ow_ID]['tid']);
    $meeting_wrapper->field_meeting_date->set($meeting_timestamp);
    node_save($meeting);
  }
  
  $committee_document = $existing_node;
  $file = new stdClass();
  if (empty($committee_document)) {
    // Create the committee document.
    $committee_document->type = 'committee_document';
    $committee_document->title = $record->doc_title;
    $committee_document->uid = 1;
    $committee_document->log = t('Imported committee document from old system with doc_ID @id', array('@id' => $record->doc_ID));
    $committee_document->status = TRUE;
    $committee_document->language = LANGUAGE_NONE;
    node_save($committee_document);

    $filename = realpath('.') . '/../private-files/committee_documents/archive/' . $committees[$record->ow_ID]['tid'] . '/' . $record->doc_file;
    $finfo = finfo_open(FILEINFO_MIME_TYPE);
    $mime = finfo_file($finfo, $filename);
    finfo_close($finfo); 

    if (!empty($mime)) {
      $file = (object) array(
        'description' => $record->doc_title,
        'filename' => $record->doc_file,
        'filemime' => $mime,
        'uid' => 1,
        'uri' => 'private://committee_documents/archive/' . $committees[$record->ow_ID]['tid'] . '/' . $record->doc_file,
        'status' => 1,
        'display' => 1,
      );

      file_save($file);
    }
  }

  $committee_document_wrapper = entity_metadata_wrapper('node', $committee_document);
  $committee_document_wrapper->field_council_access->set($record->doc_access);
  $committee_document_wrapper->field_document_approved->set($record->doc_approved);
  $committee_document_wrapper->field_document_archived->set($record->doc_archive);
  $committee_document_wrapper->body->set(array('value' => $record->doc_comments, 'format' => 'filter_html'));
  $committee_document_wrapper->field_meeting_reference->set($meeting->nid);

  if (!empty($file) && !empty($file->fid)) {
    $committee_document_wrapper->field_document_file->set((array) $file);
  }
  
  node_save($committee_document);

  return $committee_document;
}


/**
 * Implements ID_get_data().
 * Get data handler for the event abstracts.
 *
 * @return array
 *   An array of objects, each object should be the basis of later
 *   creating a node using the other callback function _name_save_node.
 */
function event_abstracts_get_data() {
  db_set_active('oldwebsite');
  $out = db_query("SET CHARACTER SET UTF8;");
  $out = db_query("SELECT * FROM rmetsdev_old_website_2.abstracts");
  db_set_active();
  return $out;
}

/**
 * Implements ID_save_node().
 * Save node handler for event abstracts.
 * out of accreditation_awards nodes and into award_profile
 *
 * @param object $record
 *   A record object. This is one of the items in the array returned
 *   by the _name_get_data callback function.
 * @param object $existing_node
 *   The node to update with this record if there is one.
 *
 * @return object|boolean
 *   The new or updated node or FALSE if nothing was saved.
 */
function event_abstracts_save_node($record, $existing_node = NULL) {
  $event_audit = variable_get('events_import-audit', array());
  if (!isset($event_audit[$record->ev_ID])) {
    drush_set_error('Could not find the imported event for event with ev_ID ' . $record->ev_ID);
    return FALSE;
  }

  $event = node_load($event_audit[$record->ev_ID]);
  if (empty($event)) {
    drush_set_error('Could not find the drupal previously imported event with nid ' . $event_audit[$record->ev_ID]);
    return FALSE;
  }

  $abstract = $existing_node;
  if (empty($abstract)) {
    $abstract = new stdClass();
    $abstract->type = 'event_abstract';
    $abstract->title = $record->abs_title;
    $abstract->uid = 1;
    $abstract->log = t('Imported abstract from old system with abs_ID @id', array('@id' => $record->abs_ID));
    $abstract->status = TRUE;
    node_save($abstract);
  }

  $abstract->status = TRUE;

  $abstract_wrapper = entity_metadata_wrapper('node', $abstract);
  $abstract_wrapper->field_event->set($event->nid);
  $abstract_wrapper->field_abstract_time_and_date->set(array('value' => strtotime($record->abs_time)));
  $abstract_wrapper->field_presenting_author->set($record->abs_author);
  $abstract_wrapper->body->set(array('value' => $record->abs_intro, 'format' => 'filtered_html'));

  if (!empty($record->abs_url)) {
    $abstract_wrapper->field_resources_link[] = array('url' => $record->abs_url, 'title' => t('External website'));
  }

  if (!empty($record->abs_pres)) {
    $uri = 'public://archive/abstracts/pdf/' . $record->abs_pres;
    if (!file_exists($uri)) {
      $found = FALSE;

      if (isset($abstract->field_grouped_files) && !empty($abstract->field_grouped_files)) {
        foreach ($abstract->field_grouped_files[LANGUAGE_NONE] as $file) {
          if ($file['uri'] == $uri) {
            $found = TRUE;
            break;
          }
        }
      }

      if (!$found) {
        $file = _curl_copy_remote('http://www.rmets.org/pdf/presentation/' . $record->abs_pres, $uri);
        $abstract->field_grouped_files[LANGUAGE_NONE][] = array(
          'fid' => $file->fid,
          'description' => $file->filename,
          'filename' => $file->filename,
          'filemime' => $file->filemime,
          'uid' => 1,
          'uri' => $file->uri,
          'status' => 1,
          'display' => 1,
        );
        unset($file);
      }
    }
  }

  if (!empty($record->abs_av)) {
    $uri = 'public://archive/abstracts/av/' . $record->abs_pres;

    if (!file_exists($uri)) {
      $found = FALSE;

      if (isset($abstract->field_grouped_files) && !empty($abstract->field_grouped_files)) {
        foreach ($abstract->field_grouped_files[LANGUAGE_NONE] as $file) {
          if ($file['uri'] == $uri) {
            $found = TRUE;
            break;
          }
        }
      }

      if (!$found) {
        $file = _curl_copy_remote('http://www.rmets.org/pdf/presentation/' . $record->abs_av, $uri);
        $abstract->field_grouped_files[LANGUAGE_NONE][] = array(
          'fid' => $file->fid,
          'description' => $file->filename,
          'filename' => $file->filename,
          'filemime' => $file->filemime,
          'uid' => 1,
          'uri' => $file->uri,
          'status' => 1,
          'display' => 1,
        );
        unset($file);
      }
    }
  }

  node_save($abstract);

  // Make sure the event is set to diplay the abstracts.
  entity_metadata_wrapper('node', $event)->field_event_display_programme->set(1);
  node_save($event);
  unset($event);

  return $abstract;
}

/**
 * Implements ID_get_data().
 * Get data handler for corporate_member_import.
 *
 * @return array
 *   An array of objects, each object should be the basis of later
 *   creating a node using the other callback function _name_save_node.
 */
function awards_get_data() {
  $results = db_query("SELECT nid from {node} WHERE type='accreditations_awards' GROUP BY title HAVING count(nid) > 1 ORDER BY nid ASC");
  $nodes = array();

  foreach ($results as $result) {
    $nodes[] = (object) array('nid' => $result->nid);
  }

  return $nodes;
}

/**
 * Implements ID_save_node().
 * Save node handler for awards. This moves award data
 * out of accreditation_awards nodes and into award_profile
 *
 * @param object $record
 *   A record object. This is one of the items in the array returned
 *   by the _name_get_data callback function.
 * @param object $existing_node
 *   The node to update with this record if there is one.
 *
 * @return object|boolean
 *   The new or updated node or FALSE if nothing was saved.
 */
function awards_save_node($record, $existing_node = NULL) {
  // Load the old node.
  $old_node = node_load($record->nid);
  $old_node_wrapper = entity_metadata_wrapper('node', $old_node);

  $membership_number = $old_node_wrapper->field_membership_number->value();
  if (empty($membership_number)) {
    drush_set_error('Could not transfer ' . $old_node->nid);
    return FALSE;
  }

  $new_node = new stdClass();
  if (empty($existing_node)) {
    // See if there is already an equivalent award_profile.
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'award_profile')
      ->fieldCondition('field_membership_number', 'value', $old_node_wrapper->field_membership_number->value(), '=')
      ->execute();

    if (isset($result['node'])) {
      // Existing profile node.
      $new_node = node_load(reset(array_keys($result['node'])));
      drush_print(' -- Found existing node with nid ' . $new_node->nid);
    }
    else {
      // New profile node.
      $new_node->type = 'award_profile';
      $new_node->title = $old_node->title;
      $new_node->uid = 1;
      $new_node->log = t('Created as a copy of an accreditaition and awards node with nid @nid', array('@nid' => $old_node->nid));
      $new_node->status = FALSE;
      node_save($new_node);
    }
  }
  else {
    $new_node = $existing_node;
  }

  $new_node_wrapper = entity_metadata_wrapper('node', $new_node);

  $new_node_wrapper->field_membership_number->set($old_node_wrapper->field_membership_number->value());
  $new_node_wrapper->field_forenames->set($old_node_wrapper->field_forenames->value());
  $new_node_wrapper->field_surname->set($old_node_wrapper->field_surname->value());
  $new_node_wrapper->field_prefix->set($old_node_wrapper->field_prefix->value());
  $new_node_wrapper->field_suffix->set($old_node_wrapper->field_suffix->value());
  $new_node_wrapper->field_public_email->set($old_node_wrapper->field_public_email->value());
  $new_node_wrapper->field_public_telephone->set($old_node_wrapper->field_public_telephone->value());
  $new_node_wrapper->field_person_picture->set($old_node_wrapper->field_person_picture->value());
  $new_node_wrapper->field_countries->set($old_node_wrapper->field_countries->value());
  $new_node_wrapper->field_languages->set($old_node_wrapper->field_languages->value());

  $address = $old_node_wrapper->field_accreditation_address->value();
  $new_node_wrapper->field_accreditation_address->set($address);

  $emp = $old_node_wrapper->field_current_employment->value();
  $new_node_wrapper->field_current_employment->set($emp);

  $emp_his = $old_node_wrapper->field_employment_history->value();
  $new_node_wrapper->field_employment_history->set($emp_his);

  $exp = $old_node_wrapper->field_expertise->value();
  $new_node_wrapper->field_expertise->set($exp);

  node_save($new_node);

  // Try and free up some memory.
  unset($new_node_wrapper);
  unset($old_node_wrapper);
  unset($old_node);
  unset($existing_node);

  return $new_node;
}

/**
 * Implements ID_get_data().
 * Get data handler for corporate_member_import.
 *
 * @return array
 *   An array of objects, each object should be the basis of later
 *   creating a node using the other callback function _name_save_node.
 */
function rmets_corporate_member_get_data() {
  db_set_active('oldwebsite');
  $out = db_query("SET CHARACTER SET UTF8;");
  $out = db_query("SELECT * FROM rmetsdev_old_website_2.corporate a INNER JOIN rmetsdev_old_website_2.members b ON a.mem_contactID = b.mem_contactID WHERE a.cm_name='3TIER'");
  db_set_active();
  return $out;
}

/**
 * Implements ID_save_node().
 * Save node handler for corporate_member_import.
 *
 * @param object $record
 *   A record object. This is one of the items in the array returned
 *   by the _name_get_data callback function.
 * @param object $existing_node
 *   The node to update with this record if there is one.
 *
 * @return object|boolean
 *   The new or updated node or FALSE if nothing was saved.
 */
function rmets_corporate_member_save_node($record, $existing_node = NULL) {
  static $lookup = array(
    'instrument_supplier' => 'Instrument supplier',
    'energy' => 'Energy',
    'service_provider' => 'Service provider',
    'publisher' => 'Publisher',
  );

  $node = empty($existing_node) ? new stdClass() : $existing_node;

  // Get the logo file.
  $uri = 'public://images/company_logos/' . $record->cm_logo;
  $logo = _curl_copy_remote('http://www.rmets.org/images/otherlogos/' . $record->cm_logo, $uri);

  $node->type = 'corporate_member';
  $node->title = $record->cm_name;
  $node->uid = 1;
  $node->log = t('Created corporate member via import script');
  $node->language = LANGUAGE_NONE;
  $node->status = $record->cm_archive ? FALSE : TRUE;

  node_save($node);

  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->body->set(array('value' => $record->cm_details, 'format' => 'full_html'));
  if ($logo) {
    $wrapper->field_company_logo->set(array(
      'fid' => $logo->fid,
      'description' => $logo->filename,
      'filename' => $logo->filename,
      'filemime' => $logo->filemime,
      'uid' => 1,
      'uri' => $logo->uri,
      'status' => 1,
      'display' => 1,
    ));
  }

  $wrapper->field_membership_number->set($record->mem_contactID);
  $wrapper->field_website->set(array('url' => $record->mem_website));

  if ($record->cm_type && isset($lookup[$record->cm_type])) {
    $terms = taxonomy_term_load_multiple(array(), array('name' => $lookup[$record->cm_type]));
    if (!empty($terms)) {
      $term = reset($terms);
      $wrapper->field_corporate_member_type->set(array($term->tid));
    }
  }

  node_save($node);

  return $node;
}

/**
 * Implements ID_get_data().
 * Get data handler for cmet_member_records.
 *
 * @return array
 *   An array of objects, each object should be the basis of later
 *   creating a node using the other callback function _name_save_node.
 */
function cmet_member_records_get_data() {
  db_set_active('oldwebsite');
  $out = db_query("SET CHARACTER SET UTF8;");
  $out = db_query("SELECT * FROM rmetsdev_old_website_2.cmet a INNER JOIN rmetsdev_old_website.members b ON a.mem_contactID = b.mem_contactID");
  db_set_active();
  return $out;
}

/**
 * Implements ID_save_node().
 * Save node handler for cmet_member_records.
 *
 * @param object $record
 *   A record object. This is one of the items in the array returned
 *   by the _name_get_data callback function.
 * @param object $existing_node
 *   The node to update with this record if there is one.
 *
 * @return object|boolean
 *   The new or updated node or FALSE if nothing was saved.
 */
function cmet_member_records_save_node($record, $existing_node = NULL) {
  $node = empty($existing_node) ? new stdClass() : $existing_node;

  if (empty($existing_node)) {
    // There might still be a node for this, check via the member number.
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'accreditations_awards')
      ->fieldCondition('field_membership_number', 'value', $record->mem_contactID, '=')
      ->execute();

    if (isset($result['node'])) {
      $nodes = entity_load('node', array(reset(array_keys($result['node']))));
      if (!empty($nodes)) {
        $node = reset($nodes);
      }
    }
  }

  $member = enterprise()->getMember($record->mem_contactID);

  if ($member) {
    $node->type = 'accreditations_awards';
    $node->title = "{$member->Forenames} {$member->Surname}";
    $node->uid = 1;
    $node->log = t('Updated details via drush import script');
    $node->revision = TRUE;
    $node->language = LANGUAGE_NONE;
    $node->status = isset($node->status) ? $node->status : FALSE;
    node_save($node);

    $wrapper = entity_metadata_wrapper('node', $node);

    $wrapper->field_prefix->set($member->Title);
    $wrapper->field_forenames->set($member->Forenames);
    $wrapper->field_surname->set($member->Surname);
    $wrapper->field_suffix->set($member->Suffixes);
    $wrapper->field_public_email->set($record->cmet_email);
    $wrapper->field_public_telephone->set($record->cmet_tel);
    $wrapper->field_accreditation_address->set(array('value' => $record->cmet_address, 'format' => 'full_html'));
    $wrapper->field_current_employment->set(array('value' => $$record->cmet_recJob, 'format' => 'full_html'));
    $wrapper->field_employment_history->set(array('value' => $$record->cmet_emp, 'format' => 'full_html'));
    $wrapper->field_expertise->set(array('value' => $$record->cmet_expert, 'format' => 'full_html'));
    $wrapper->field_countries->set($record->cmet_countries);
    $wrapper->field_languages->set($record->cmet_lang);

    node_save($node);

    return $node;
  }

  return FALSE;
}

/**
 * Implements ID_get_data().
 * Get the list of committee documents for import.
 */
function committee_papers_get_data() {
  db_set_active('oldwebsite');
  $out = db_query("SET CHARACTER SET UTF8;");
  $out = db_query("SELECT * FROM rmetsdev_old_website_2.documents d INNER JOIN rmetsdev_old_website.owners o ON d.ow_ID = o.ow_ID");
  db_set_active();
  return $out;
}

/**
 * Implements ID_save_node().
 * Save or update a committee paper as a node.
 */
function committee_papers_save_node($record, $existing_node = NULL) {
  // TODO - save the nodes!
}

/**
 * Implements ID_get_data().
 * Get data handler for cmet_member_records.
 *
 * @return array
 *   An array of objects, each object should be the basis of later
 *   creating a node using the other callback function _name_save_node.
 */
function image_gallery_get_data() {
  db_set_active('oldwebsite');
  $out = db_query("SET CHARACTER SET UTF8;");
  $out = db_query("SELECT * FROM rmetsdev_old_website_2.images i WHERE i.img_use='cloudbank' AND i.img_archive LIKE 0");
  db_set_active();
  return $out;
}


/**
 * Implements ID_save_node().
 * Save node handler for corporate_member_import.
 *
 * @param object $record
 *   A record object. This is one of the items in the array returned
 *   by the _name_get_data callback function.
 * @param object $existing_node
 *   The node to update with this record if there is one.
 *
 * @return object|boolean
 *   The new or updated node or FALSE if nothing was saved.
 */
function image_gallery_save_node($record, $existing_node = NULL) {

  $node = empty($existing_node) ? new stdClass() : $existing_node;

  // Get the logo file.
  $uri = 'private://cloudbank/' . $record->img_file;
  $logo = _curl_copy_remote('http://images.rmets.org/cloudbank/' . $record->img_file, $uri);

  $node->type = 'image_gallery';
  $node->title = $record->img_title;
  $node->uid = 1;
  $node->log = t('Created Image via import script');
  $node->language = LANGUAGE_NONE;
  $node->status = 1;

  node_save($node);

  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->body->set(array('value' => $record->img_desc, 'format' => 'full_html'));
  if ($logo) {
    $wrapper->field_gallery_image->set(array(
      'fid' => $logo->fid,
      'description' => $logo->filename,
      'filename' => $logo->filename,
      'filemime' => $logo->filemime,
      'uid' => 1,
      'uri' => $logo->uri,
      'status' => 1,
      'display' => 1,
    ));
  }

  $wrapper->field_location->set($record->img_where);
  //$wrapper->field_photographer->set(array('url' => $record->mem_website));
  if (preg_match('/^19/', $record->img_taken) || preg_match('/^20/', $record->img_taken)) {
    $wrapper->field_image_date->set(strtotime($record->img_taken));
  }
  $wrapper->field_import_id->set($record->img_ID);
  
  db_set_active('oldwebsite');
  $out = db_query("SELECT * FROM keylinks JOIN keywords ON keylinks.key_ID = keywords.key_ID WHERE item_id=:img_id", array(':img_id' => $record->img_ID));
  $out2 = db_query("SELECT * FROM copyright WHERE copy_ID=:img_id", array(':img_id' => $record->copy_ID))->fetchObject();
  db_set_active();
  $tids = array();

  $wrapper->field_keywords = array();
  foreach ($out AS $o) {
    $term = taxonomy_get_term_by_name($o->key_word, "keywords");
    if ($term && FALSE) {
      $tids[] = $term[0]->tid;
      $term = array_pop($term);
    }
    else {
      $term = entity_property_values_create_entity('taxonomy_term', array(
        'name' => $o->key_word, 
        'vocabulary' => 16,
      ))->save()->value();
      $tids[] = $term->tid;
    }
    $wrapper->field_keywords[] = array_pop($tids);
  }
  $wrapper->field_photographer->set($out2->copy_firstname . ' ' . $out2->copy_surname);
  
  $copy = $record->copy_ID == 2 ? 'retain' : 'rmets';
  $wrapper->field_copyright->set($copy);
  
  node_save($node);
  return $node;
}

/**
 * Implements ID_get_data().
 * Get data handler for cmet_member_records.
 *
 * @return array
 *   An array of objects, each object should be the basis of later
 *   creating a node using the other callback function _name_save_node.
 */
function news_get_data() {
  db_set_active('oldwebsite');
  $out = db_query("SET CHARACTER SET UTF8;");
  $out = db_query("SELECT * from rmetsdev_old_website_2.news WHERE nw_approved LIKE 1");
  db_set_active();
  return $out;
}


/**
 * Implements ID_save_node().
 * Save node handler for corporate_member_import.
 *
 * @param object $record
 *   A record object. This is one of the items in the array returned
 *   by the _name_get_data callback function.
 * @param object $existing_node
 *   The node to update with this record if there is one.
 *
 * @return object|boolean
 *   The new or updated node or FALSE if nothing was saved.
 */
function news_save_node($record, $existing_node = NULL) {

  $node = empty($existing_node) ? new stdClass() : $existing_node;

  // Get the logo file.
  if ($record->nw_picture != 'blank.jpg') {
    $uri = 'public://images/news_images/' . $record->nw_picture;
    $logo = _curl_copy_remote('http://www.rmets.org/images/news/' . $record->nw_picture, $uri);
  }
  else {
    $uri = FALSE;
    $logo = FALSE;
  }

  $node->type = 'news';
  $node->title = $record->nw_headline;
  $node->uid = 1;
  $node->log = t('Created News via import script');
  $node->language = LANGUAGE_NONE;
  $node->status = 1;
  $node->created = strtotime(nw_created);

  node_save($node);

  $wrapper = entity_metadata_wrapper('node', $node);
  $body = $record->nw_story;
  if ($record->nw_url) {
    $body .= '<p><a href="' . $record->nw_url . '">More Info...</a></p>';
  }
  $wrapper->body->set(array('value' => $body, 'format' => 'full_html'));
  if ($logo) {
    $wrapper->field_image->set(array(
      'fid' => $logo->fid,
      'description' => $logo->filename,
      'filename' => $logo->filename,
      'filemime' => $logo->filemime,
      'uid' => 1,
      'uri' => $logo->uri,
      'status' => 1,
      'display' => 1,
    ));
  }

  //$wrapper->field_photographer->set(array('url' => $record->mem_website));
  $wrapper->field_news_date->set(strtotime($record->nw_created));
  

  $type = $record->nw_type == 'vacancy' ? 'Jobs' : 'News';
  $wrapper->field_type->set($type);

  node_save($node);

  return $node;
}

/**
 * Implements ID_get_data().
 * Get data handler for cmet_member_records.
 *
 * @return array
 *   An array of objects, each object should be the basis of later
 *   creating a node using the other callback function _name_save_node.
 */
function events_get_data() {
  db_set_active('oldwebsite');
  $out = db_query("SET CHARACTER SET UTF8;");
  $out = db_query("SELECT * from rmetsdev_old_website_2.events");
  db_set_active();
  return $out;
}


/**
 * Implements ID_save_node().
 * Save node handler for corporate_member_import.
 *
 * @param object $record
 *   A record object. This is one of the items in the array returned
 *   by the _name_get_data callback function.
 * @param object $existing_node
 *   The node to update with this record if there is one.
 *
 * @return object|boolean
 *   The new or updated node or FALSE if nothing was saved.
 */
function events_save_node($record, $existing_node = NULL) {

  if (empty($existing_node) && $record->ev_approved == 0) {
    // Don't create unapproved nodes.
    return FALSE;
  }

  $node = empty($existing_node) ? new stdClass() : $existing_node;

  // Get the logo file.

  $node->type = 'event';
  $node->title = $record->ev_title;
  $node->uid = 1;
  $node->log = t('Created News via import script');
  $node->language = LANGUAGE_NONE;
  $node->status = 1;

  node_save($node);

  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->body->set(array('value' => $record->ev_info, 'format' => 'full_html'));
  $wrapper->field_event_email->set(array('value' => $record->ev_contact, 'format' => 'full_html'));
  $location = '';
  if ($record->ev_loc) {
    $location .= $record->ev_loc;
  }
  if ($record->ev_dir) {
    $location .= $record->ev_dir;
  }
  $wrapper->field_summary_location->set(array('value' => $location, 'format' => 'full_html'));
  $wrapper->field_event_date->set(array('value' => strtotime($record->ev_date), 'value2' => strtotime($record->ev_date . ' +3660 seconds'), 'date_type' => 'datestamp', 'timezone' => 'BST', 'timezone_db' => 'BST'));

  $mapping_owner = array(
'association of british climatologists' => 0,
'atmospheric chemistry' => 78,
'aviation meteorology' => 79,
'data assimilation' => 80,
'dynamical problems' => 81,
'east anglia local centre' => 31,
'east midlands local centre' => 32,
'european meteorological society' => 0,
'history of meteorology and physical oceanography' => 0,
'irish meteorological society' => 0,
'meteorological observing systems' => 83,
'none specified' => 0,
'north east local centre' => 33,
'north west local centre' => 34,
'other' => 29,
'physical Processes' => 84,
'royal meteorological society' => 0,
'royal society' => 0,
'satellite meteorology and oceanography' => 85,
'scottish local centre' => 35,
'south east local centre' => 36,
'south west local centre' => 37,
'welsh local centre' => 38,
'west midlands group' => 39,
'yorkshire centre' => 40,
  );
  $mapping_subtype = array(
    'wednesday' => 26,
    'saturday' => 26,
    'national' => 26,
    'external' => 29,
    'rmets' => 1869
  );
  $mapping_type = array(
    'conference' => 30 
  );
  db_set_active('oldwebsite');
  $out = db_query('SELECT * FROM owners WHERE ow_ID = :id', array(':id' => $record->ev_owner))->fetchObject(); 
  db_set_active();
  $tids = array();
  $wrapper->field_event_type = array();
  if ($mapping_subtype[strtolower($record->ev_subtype)]) {
    $wrapper->field_event_type[] = $mapping_subtype[strtolower($record->ev_subtype)];
  }
  if ($mapping_type[strtolower($record->ev_type)]) {
    $wrapper->field_event_type[] = $mapping_type[strtolower($record->ev_type)];
  }
  if ($mapping_owner[strtolower($out->ow_title)]) {
    $wrapper->field_event_type[] = $mapping_owner[strtolower($out->ow_title)];
  }

  
  

  node_save($node);

  return $node;
}
