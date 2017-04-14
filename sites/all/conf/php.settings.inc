<?php

/**
 * @file
 * PHP configuration
 */

// Long time out needed for some requests.
set_time_limit(120);

ini_set('memory_limit', '512M');

ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);
