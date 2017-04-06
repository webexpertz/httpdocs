<?php

// $Id$

/**
 * @file
 * The theme template for rendering a collection of file attachment groups
 * Variables
 * $groups - Array of groups. Each group is an array containing a 'title' (which might be empty) and 'content' HTML
 */
?>
<div class="downloads">
  <h2>Document downloads</h2>
  <?php foreach ($groups as $group) : ?>
    <?php if ($group['title']) : ?>
      <h4><?php print $group['title']; ?></h4>
    <?php endif; ?>
    <?php print $group['content']; ?>
  <?php endforeach; ?>
</div>
