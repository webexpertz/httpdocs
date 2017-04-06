<?php

/**
 * @file
 * Home of the DBFetcher and related classes.
 */

/**
 * Definition of the import batch object created on the fetching stage by
 * DBFetcher.
 */
class DBFetcherResult extends FeedsFetcherResult {

  /**
   * Overrides parent::getRaw();
   */
  public function getRaw() {
    return unserialize($this->sanitizeRaw(serialize($this->raw)));
  }

}

/**
 * Fetches data via DB.
 */
class DBFetcher extends FeedsFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);
    if (empty($source_config)) {
      $source_config = $this->getConfig();
    }
    // @TODO: Raise exceptions, avoid global meltdown

    $query_string = $this->cleanQuery($source_config['database_query'], $source_config['limit']);
    $key = $source_config['database'];

    if ($source_config['limit'] <= 0) {
      $query = Database::getConnection('default', $key)->query($query_string);
      $result = $query->fetchAll(PDO::FETCH_ASSOC);
      return new DBFetcherResult($result);
    }

    // Batch it.
    $state = $source->state(FEEDS_FETCH);
    if (!isset($state->num_rows)) {
      $state->num_rows = $state->total = Database::getConnection('default', $key)->query('SELECT count(*) FROM (' . $query_string . ') as records')->fetchField();
    }
    if ($state->num_rows) {
      $query = Database::getConnection('default', $key)->queryRange($query_string, $state->total - $state->num_rows, $source_config['limit']);
      $state->num_rows -= $query->rowCount();
      $result = $query->fetchAll(PDO::FETCH_ASSOC);
      $state->progress($state->total, $state->total - $state->num_rows);
      return new DBFetcherResult($result);
    }
  }

  /**
   * Overrides parent:sourceDefaults()
   */
  public function sourceDefaults() {
    return array();
  }

  /**
   * Define defaults.
   */
  public function configDefaults() {
    global $databases;
    $db_names = array();
    foreach (array_keys($databases) as $db_name) {
      $db_names[$db_name] = $db_name;
    }
    unset($db_names[array_search('default', $db_names)]);
    return array(
      'database' => current($db_names),
      'database_query' => '',
      'limit' => 0,
      'allow_override' => TRUE,
    );
  }

  /**
   * Source form.
   */
  public function sourceForm($source_config) {
    global $databases;
    $form = array();
    $importer = feeds_importer($this->id);
    $importer_config = $importer->getConfig();

    $config = $this->getConfig();
    if (empty($source_config) || (!$config['allow_override'] && empty($source_config['config'])) ) {
      $source_config = $config;
    }

    if (isset($source_config['allow_override']) &&
        !$source_config['allow_override'] &&
        empty($source_config['config'])) {
      return;
    }
    $db_names = array();
    foreach (array_keys($databases) as $db_name) {
      $db_names[$db_name] = $db_name;
    }
    $source_config += $this->sourceDefaults();
    unset($db_names[array_search('default', $db_names)]);
    $form['database'] = array(
      '#type' => 'select',
      '#title' => t('Database'),
      '#options' => $db_names,
      '#required' => TRUE,
      '#default_value' => $source_config['database'],
    );

    $form['database_query'] = array(
      '#type' => 'textarea',
      '#title' => t('Database query'),
      '#description' => t('The SQL query to run on the database. Be sure to include all necessary fields.'),
      '#required' => TRUE,
      '#default_value' => $source_config['database_query'],
    );

    $form['limit'] = array(
      '#type' => 'textfield',
      '#title' => t('Limit'),
      '#description' => t('Specify the limit of nodes to be processed withing a single request. Use it wisely to save memory on big tables. Leave it as 0 for no limit.'),
      '#default_value' => $source_config['limit'],
    );
    return $form;
  }

  /**
   * Override parent::configForm().
   * Based on code from Feeds XPathParser.
   */
  public function configForm(&$form_state) {
    $config = $this->getConfig();
    $config['config'] = TRUE;
    $form = $this->sourceForm($config);
    $form['allow_override'] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow source configuration override'),
      '#default_value' => $config['allow_override'],
    );
    return $form;
  }

  /**
   * Override parent::sourceFormValidate().
   *
   * If the values of this source are the same as the base config we set them to
   * blank to that the values will be inherited from the importer defaults.
   *
   * @param &$values
   *   The values from the form to validate, passed by reference.
   */
  public function sourceFormValidate(&$values) {
    $config = $this->getConfig();
    $allow_override = $config['allow_override'];
    unset($config['allow_override']);
    ksort($values);
    ksort($config);
    if ($values === $config || !$allow_override) {
      $values = array();
      return;
    }

    $this->configFormValidate($values);
  }

  /**
   * Clean the query string
   * @param $query
   * @return cleaned-up query string
   */
  public function cleanQuery($query, $limit = 0) {
    // Removes LIMIT on query to avoid troubles when using queryRange()
    if ($limit > 0) {
      $query = preg_replace('#(LIMIT|limit) *[0-9]*, *[0-9]*#', '', $query);
    }

    // Removes accidental semicolon at the end of the query
    return trim($query, ';');
  }
}
