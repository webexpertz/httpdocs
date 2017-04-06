<?php
/**
* @file
* Default theme implementation to display a block.
*
* Available variables:
* - $block->subject: Block title.
* - $content: Block content.
* - $block->module: Module that generated the block.
* - $block->delta: An ID for the block, unique within each module.
* - $block->region: The block region embedding the current block.
* - $classes: String of classes that can be used to style contextually through
* CSS. It can be manipulated through the variable $classes_array from
* preprocess functions. The default values can be one or more of the
* following:
* - block: The current template type, i.e., "theming hook".
* - block-[module]: The module generating the block. For example, the user
* module is responsible for handling the default user navigation block. In
* that case the class would be 'block-user'.
* - $title_prefix (array): An array containing additional output populated by
* modules, intended to be displayed in front of the main title tag that
* appears in the template.
* - $title_suffix (array): An array containing additional output populated by
* modules, intended to be displayed after the main title tag that appears in
* the template.
*
* Helper variables:
* - $classes_array: Array of html class attribute values. It is flattened
* into a string within the variable $classes.
* - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
* - $zebra: Same output as $block_zebra but independent of any block region.
* - $block_id: Counter dependent on each block region.
* - $id: Same output as $block_id but independent of any block region.
* - $is_front: Flags true when presented in the front page.
* - $logged_in: Flags true when the current user is a logged-in member.
* - $is_admin: Flags true when the current user is an administrator.
* - $block_html_id: A valid HTML ID and guaranteed unique.
*
* @see template_preprocess()
* @see template_preprocess_block()
* @see template_process()
*
* @ingroup themeable
*/
?>
<?php
$hxclass = '';
$pre_title = '';
$w = 'div';
$hx = 'h2';
if ($block->module == 'facetapi' || $block->module == 'apachesolr_search'):
 $hx = 'h4';
elseif ($block_html_id == 'block-menu-block-1'):
 $hx = 'div';
 $title_attributes = ' class="head"';
elseif ($block->region == 'footer'):
  $w = 'li';
elseif ($block_html_id == 'block-views-news-block-1'):
  print '<div class="news left block">';
  $pre_title = '<ul class="inline right">
                  <li class="first"><a class="rss" href="/news/feed">RSS icon</a></li>
                  <li class="border-right"><a class="arrow-right blue" href="/news">View all News</a></li>
                  <li class="last"><a class="arrow-right blue" href="/news/jobs">View all job vacancies</a></li>
                </ul>';
elseif ($block_html_id == 'block-views-events-and-meetings-block-1'):
  $pre_title = '<div class="block-head">
<a class="rss right" href="/events/feed">RSS feed</a>
<h3>Events &amp; Meetings</h3>
</div>';
  $block->subject = NULL;   
endif;


?>
<<?php print $w ?> id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php print $pre_title; ?>
<?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
<<?php print $hx ?><?php print $title_attributes; ?>><?php print $block->subject ?></<?php print $hx; ?>>
<?php endif;?>
<?php print render($title_suffix); ?>
<div class="content"<?php print $content_attributes; ?>>
<?php print $content ?>
</div>
</<?php print $w ?>> 
<?php
if ($block_html_id == 'block-views-news-block-1'):
  print '</div>';
endif;  
?>

