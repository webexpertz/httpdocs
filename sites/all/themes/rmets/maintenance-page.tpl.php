<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 */

?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8" />

    <title>Royal Meteorological Society :: Error</title>

    <link rel="stylesheet" type="text/css" media="all" href="/<?php print path_to_theme(); ?>/assets/css/normalize.css" />
    <link rel="stylesheet" type="text/css" media="all" href="/<?php print path_to_theme(); ?>/assets/css/rmets.css" />
    <link href="http://fonts.googleapis.com/css?family=Droid+Sans:400,700" rel="stylesheet" type="text/css" />

  </head>
  <body class="no-sidebars">

    <div id="wrapper" class="clearfix">

      <div id="header" class="block clearfix">
        <div class="cloud"></div>
        <div class="header-inner">
              <div class="logo-wrapper">
                <a href="/" class="logo ir">Royal Meteorological Society</a>
              </div>
        </div>
      </div>

          <div id="middle" class="left block clearfix">

                <div id="content" class="right clearfix">
                  <h1>Error</h1>
                  <?php print $messages; ?>
                  <?php print $content; ?>
                </div>

          </div>

    </div>

        <div id="footer" class="block clearfix">
          <div class="col one left">
            <div class="footer-logo"><img src="/<?php print path_to_theme(); ?>/assets/images/foot-logo.png" alt="logo" /></div>
            <p><strong>Royal Meteorological Society</strong><br />
            104 Oxford Road<br />
            Reading<br />
            RG1 7LL</p>
            <p>RMetS is a registered charity No. 208222</p>
          </div>
            <div class="col two left">
              <p><strong>Telephone: 0118 956 8500<br />Fax: 0118 956 8571</strong></p>
              <ul>
                <li>General: <a href="/">info@rmets.org</a></li>
                <li>Chief Executive: <a href="/">chiefexec@rmets.org</a></li>
                <li>Web: <a href="/">webmaster@rmets.org</a></li>
                <li>Membership: <a href="/">membership@rmets.org</a></li>
              </ul>
            </div>
          </div>

    <script type="text/javascript" src="/<?php print path_to_theme(); ?>/assets/js/jquery.min.js"></script>
    <script type="text/javascript" src="/<?php print path_to_theme(); ?>/assets/js/sitename.js"></script>
  </body>
</html>
