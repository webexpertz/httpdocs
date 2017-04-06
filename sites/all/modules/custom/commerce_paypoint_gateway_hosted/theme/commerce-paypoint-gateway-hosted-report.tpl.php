<?php

/**
 * @file
 * The report shown to the user after return from PayPoint.
 *
 * Variables
 *  - $success (boolean) TRUE for successful transaction
 *  - $title (string) Title message
 *  - $message (string) Main message
 *  - $details (object)
 *    - $order_id (int)
 *    - $total_cost (int)
 */

?>
<div>
  <h1 class="<?php print $success ? 'green' : 'red'; ?>"><?php print $title; ?></h1>
  <p><?php print $message; ?>
  <p>Payment Submitted on <strong><?php print date('l jS F Y') . ' at ' . date('H:i:s'); ?></strong></p>
  <?php if (is_object($details) && isset($details->nid) && is_numeric($details->order_id)) : ?>
    <p>Your Order ID for reference is <strong><?php print $details->order_id; ?></strong> (please make a note of this for future communication)</p>
  <?php endif; ?>
  <p><a href="/">Continue</a></p>
</div>
