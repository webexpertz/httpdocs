<?php

// $Id$

/**
 * @file
 * The theme template for rendering a collection of file attachment groups
 * Variables
 * $groups - Array of groups. Each group is an array containing a 'title' (which might be empty) and 'content' HTML
 */
?>
<div class="downloads beige-block block resources">
  <h2>Resources</h2>
  <?php foreach ($groups as $group): ?>
    <?php if ($group['title']) : ?>
      <h3><?php print $group['title']; ?></h3>
    <?php endif; ?>
    <?php print $group['content']; ?>
  <?php endforeach; ?>
  <?php if (isset($entity->field_resources_link) && count($entity->field_resources_link)): ?>
    <h3>External links</h3>
    <?php $resources = field_view_field('node', $entity, 'field_resources_link'); ?>
    <?php $out = '<ul class="external-link-list">'; ?>
    <?php foreach ($resources AS $id => $resource): ?>
      <?php if (is_numeric($id) && isset($resource['#markup'])): ?>
        <?php $out .= '<li>' . $resource['#markup'] . '</li>'; ?>
      <?php endif; ?>
    <?php endforeach; ?>
    <?php $out .= '</ul>'; ?>
    <?php print $out; ?>
  <?php endif; ?>
</div>
