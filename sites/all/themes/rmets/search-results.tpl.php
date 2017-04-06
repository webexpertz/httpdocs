<?php
/**
* @file
* Default theme implementation for displaying search results.
*
* This template collects each invocation of theme_search_result(). This and
* the child template are dependent to one another sharing the markup for
* definition lists.
*
* Note that modules may implement their own search type and theme function
* completely bypassing this template.
*
* Available variables:
* - $search_results: All results as it is rendered through
* search-result.tpl.php
* - $module: The machine-readable name of the module (tab) being searched, such
* as "node" or "user".
*
*
* @see template_preprocess_search_results()
 */

?>
<?php if (arg(1) == 'image-gallery'): ?>
  <?php if ($search_results): ?>
    <h2><?php print t('Search results');?></h2>
    <?php global $user; ?>
    <?php $text = $user->uid ? 'Submit an image' : 'To submit images please log in or create an account'; ?>
    <?php $url = $user->uid ? '/node/add/image-gallery?destination=weather-and-climate/image-gallery/search' : url('user', array('query' => drupal_get_destination())); ?>
    <a class="image-gallery-button button-link large" href="<?php print $url; ?>"><?php print $text; ?></a>
    <ul class="gallery clearfix">
    <?php print $search_results; ?>
    </ul>
    <?php print $pager; ?>
  <?php else : ?>
    <h2><?php print t('Your search yielded no results');?></h2>
    <?php print search_help('search#noresults', drupal_help_arg()); ?>
  <?php endif; ?>
<?php elseif (arg(0) == 'events'): ?>
  <?php if ($search_results): ?>
    <h2><?php print t('Search results');?></h2>
    <ul class="events no-thumbs list clearfix">
    <?php print $search_results; ?>
    </ul>
    <?php print $pager; ?>
  <?php else : ?>
    <h2><?php print t('Your search yielded no results');?></h2>
    <?php print search_help('search#noresults', drupal_help_arg()); ?>
  <?php endif; ?>
<?php else: ?>
  <?php if ($search_results): ?>
    <h2><?php print t('Search results');?></h2>
    <ol class="search-results <?php print $module; ?>-results">
    <?php print $search_results; ?>
    </ol>
    <?php print $pager; ?>
  <?php else : ?>
    <h2><?php print t('Your search yielded no results');?></h2>
    <?php print search_help('search#noresults', drupal_help_arg()); ?>
    <?php endif; ?>
<?php endif;
