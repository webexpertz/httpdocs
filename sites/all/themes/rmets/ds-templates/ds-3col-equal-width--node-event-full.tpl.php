<?php

/**
 * @file
 * Display Suite 3 column equal width template.
 */
?>
  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if ($left): ?>
    <?php print $left; ?>
  <?php endif; ?>

  <?php if ($middle): ?>
    <div class="event-details beige-block block">
      <?php print $middle; ?>
    </div>
  <?php endif; ?>

  <?php if ($right): ?>
    <?php print $right; ?>
  <?php endif; ?>
