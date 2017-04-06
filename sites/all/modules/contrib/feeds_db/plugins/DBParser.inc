<?php

/**
 * Parses a given DB result
 */
class DBParser extends FeedsParser {

  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $source_config = $source->getConfigFor($this);
    $state = $source->state(FEEDS_PARSE);

    return new FeedsParserResult($fetcher_result->getRaw());
  }

  /**
   * Override parent::getMappingSources().
   */
  public function getMappingSources() {
    return FALSE;
  }

  /**
   * Override parent::getSourceElement() to use only lower keys.
   */
  public function getSourceElement(FeedsSource $source, FeedsParserResult $result, $element_key) {
    // We just make sure it's all lowercase
    $element_key = drupal_strtolower($element_key);

    return parent::getSourceElement($source, $result, $element_key);
  }
}
