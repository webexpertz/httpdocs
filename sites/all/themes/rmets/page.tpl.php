<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 */
?>

  <div id="wrapper" class="clearfix">

    <div id="header" class="block clearfix noprint"><div class="header-inner"><div class="cloud"></div>
<ul class="inline right site-links">
  <li><a href="/news">News</a></li>
  <li><a href="<?php print url('node/5'); ?>">Contact us</a></li>
  <li><a href="<?php print url('node/3652'); ?>">Press</a></li>
  <?php if ($my_account_link) : ?>
  <li><?php print $my_account_link; ?></li>
  <?php endif; ?>
  <?php if ($basket_items) : ?>
    <li><a href="/cart">View basket (<?php print $basket_items; ?>)</a></li>
  <?php endif; ?>
  <?php if ($checkout_link) : ?>
    <li><?php print $checkout_link; ?></li>
  <?php endif; ?>
  <li><a class="accsys" href="/accsys">ACCSYS</a></li>
  <!--<li><a class="welsh" href="<?php /*print url('node/3653'); */?>">Welsh</a></li>-->
  <!--<li class="no-borders social-link"><a class="social li" href="/">Linkedin</a></li>-->
  <li class="no-borders social-link"><a class="social tw" href="http://twitter.com/#!/rmets">Twitter</a></li>
  <!--<li class="no-borders social-link"><a class="social fa" href="/">Facebook</a></li>-->
<?php global $user; ?>
<?php if ($user->uid): ?>
  <li class="no-borders"><a class="button-link-small" href="/user/logout">Logout</a></li>
<?php else: ?>
<li class="no-borders"><a class="button-link-small" href="/user"><?php print t('Login or register'); ?></a></li>
<?php endif; ?>
</ul>

<div class="logo-wrapper">
  <a class="logo ir" href="/"><?php print $site_name; ?></a>
</div>


      <div class="search"><?php print render($page['header']); ?></div>

    </div></div> <!-- /.header-inner, /#header -->

    <?php if ($main_menu) : ?>
      <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('primary-nav', 'horizontal-nav', 'block', 'clearfix', 'noprint')), 'heading' => NULL)); ?>
    <?php endif; ?>


    <?php print $messages; ?>
<div id="middle" class="<?php print implode(' ', $middle_classes); ?>">
    <?php if ($breadcrumb): ?>
      <div id="breadcrumb" class="breadcrumb noprint"><?php print $breadcrumb; ?></div>
    <?php endif; ?>

      <?php if ($page['sidebar_first'] || $page['search']): ?>
        <div id="sidebar-first" class="column sidebar left"><div class="section">
          <?php print render($page['sidebar_first']); ?>
<?php if ($page['search']): ?>
<div class="beige-block filter block">
<div class="head">Filter your results...</div>
          <?php print render($page['search']); ?>
</div>
<?php endif; ?>
        </div></div> <!-- /.section, /#sidebar-first -->
      <?php endif; ?>

      <div id="content" class="column <?php print (drupal_is_front_page() || (!$page['sidebar_first'] && !$page['sidebar_second'])) ? 'left' : 'right'; ?> clearfix"><div class="section">
        <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php print $feed_icons; ?>
        <?php if ($title): ?><h1><?php print $title; ?></h1><?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
        <?php print render($page['content']); ?>
      </div> <!-- /.section, /#content -->

    </div> <!-- /#content -->
      <?php if ($page['sidebar_second']): ?>
        <div id="sidebar-second" class="column sidebar right"><div class="section">
          <?php print render($page['sidebar_second']); ?>
        </div></div> <!-- /.section, /#sidebar-second -->
      <?php endif; ?>
    </div> <!-- /#middle -->
<?php if (drupal_is_front_page()): ?>
<div class="block left clear" id="adverts">
  <ul class="inline left">
      <?php print render($page['footer']); ?>
  </ul>
</div>
<?php endif; ?>


  </div> <!-- /#wrapper -->

    <div id="footer" class="block clearfix noprint"><div class="section">
					<div class="col one left">
						<div class="footer-logo"><img alt="logo" src="/sites/all/themes/rmets/assets/images/foot-logo.png" /></div>
						<p><strong>Royal Meteorological Society</strong><br />
						104 Oxford Road<br />
						Reading<br />
						RG1 7LL</p>
						<p>RMetS is a registered charity No. 208222</p>
					</div>
						<div class="col two left">
							<p><strong>Telephone: 0118 956 8500</strong></p>
							<ul>
								<li>General: <a href="mailto:info@rmets.org">info@rmets.org</a></li>
								<li>Web: <a href="mailto:webmaster@rmets.org">webmaster@rmets.org</a></li>
								<li>Membership: <a href="mailto:membership@rmets.org">membership@rmets.org</a></li>
								<li>Accreditation: <a href="mailto:accreditation@rmets.org">accreditation@rmets.org</a></li>
							</ul>
						</div>
							<div class="col three left">
								<ul>
									<li><a href="<?php print url('node/3648'); ?>">FAQs</a></li>
									<li><a href="/sitemap">Sitemap</a></li>
									<li><a href="<?php print url('node/3649'); ?>">Cookies</a></li>
									<li><a href="<?php print url('node/3650'); ?>">Privacy and payments</a></li>
									<li><a href="<?php print url('node/3651'); ?>">Terms and conditions</a></li>
									<li><a href="<?php print url('node/3652'); ?>">Press</a></li>
								</ul>
							</div>
    </div></div> <!-- /.section, /#footer -->
