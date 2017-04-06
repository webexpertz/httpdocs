<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
if (!$row->_field_data['node_field_data_field_member_profile_nid']['entity']->status && !user_access('view published content')) {
  return;
}
$award_profile_alias = drupal_lookup_path('alias', 'node/' . $row->node_field_data_field_member_profile_nid);
$award_type_query = array('query' => array('award_id' => $row->taxonomy_term_data_field_data_field_award_type_tid));
?>
<?php print l('View', $award_profile_alias, $award_type_query); ?>
