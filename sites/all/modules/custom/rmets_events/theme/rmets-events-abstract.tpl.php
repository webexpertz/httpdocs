<?php
/**
 * @file
 */
?>
<div class="event-details">
  <p><strong class="label-inline">Speaker(s):&nbsp;</strong><?php print $speakers; ?></p>
  <?php if (!empty($authors)) : ?>
  <p><strong class="label-inline">Other Author(s):&nbsp;</strong><?php print $authors; ?></p>
  <?php endif; ?>
  <?php if (!empty($theme)) : ?>
  <p><strong class="label-inline">Theme:&nbsp;</strong><?php print $theme; ?></p>
  <?php endif; ?>
  <h3>Abstract</h3>
  <p><?php print $summary; ?></p>
  <p><strong class="label-inline">Presented:&nbsp;</strong><?php print $event_name; ?>, <?php print $date; ?> <?php print $time; ?> <?php if (!empty($number)) : ?><strong class="label-inline">Abstract No.&nbsp;</strong> <?php print $number; ?><?php endif; ?></p>
  <p><strong class="label-inline">Venue Address:&nbsp;</strong><?php print $venue; ?></p>

  <?php if (!empty($event_speakers)) : ?>
    <p>&nbsp;</p>
    <h3>Speakers Biography</h3>
    <?php foreach ($event_speakers as $speaker) : /** @var \Drupal\rmets_crm\Model\EventSpeaker $speaker */ ?>
    <p><strong class="label-inline"><?php print $speaker->getSalutation(); ?>:&nbsp;</strong><?php print $speaker->getBiography(); ?></p>
    <?php endforeach; ?>
  <?php endif; ?>
</div>