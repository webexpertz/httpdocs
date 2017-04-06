<?php

// $Id$

/**
 * @file
 * Theme template file defining the output of a single group of download links
 */
?>
<ul class="download-list">
  <?php foreach ($group as $file) : ?>
  <li class="<?php print $file['mime']; ?>"><?php print $file['link']; ?></li>
  <?php endforeach; ?>
</ul>
