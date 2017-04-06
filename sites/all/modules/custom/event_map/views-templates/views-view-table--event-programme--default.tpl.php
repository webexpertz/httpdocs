<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */

$modified_rows = array();
$last_date = '';

foreach ($rows as $row) {
  $this_dates = explode(' to ', $row['field_event_session_start_time_2']);
  $this_date = date('l j F Y', $this_dates[0]);

  if ($this_date != $last_date) {
    $modified_rows[] = array('<strong>' . $this_date . '</strong>');
    $last_date = $this_date;
  }

  if ($row['field_event_session_additional'] == '1') {
    $row['title'] = strip_tags($row['title']);
  }

  unset($row['field_event_session_start_time_2']);
  unset($row['field_event_session_additional']);
  $row['field_event_session_start_time'] = str_replace(' to ', '-', $row['field_event_session_start_time']);
  $modified_rows[] = $row;
}

unset($header['field_event_session_start_time_2']);
unset($header['field_event_session_additional']);

foreach ($modified_rows as $count => $row) {
  $row_classes[$count] = array(0 => ($count % 2 ? 'odd' : 'even'));
}

?>
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
          <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
            <?php print $label; ?>
          </th>
        <?php endforeach; ?>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($modified_rows as $row_count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$row_count]); ?>">
        <?php if (count($row) == 1) : ?>
          <td colspan="5"><?php print $row[0]; ?></td>
        <?php else : ?>
          <?php foreach ($row as $field => $content): ?>
            <td>
              <?php print $content; ?>
            </td>
          <?php endforeach; ?>
        <?php endif; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
