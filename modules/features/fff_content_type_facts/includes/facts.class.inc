<?php

/**
 * @file
 * Feed parser for data feeds from globus data about team events. This feed
 * parser can be used by the feeds module.
 */

class FactsParser extends FeedsParser {

  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {

    // Load library helper functions.
    feeds_include_library('common_syndication_parser.inc', 'common_syndication_parser');

    // Parser data
    $xml = new SimpleXMLElement($fetcher_result->getRaw());

    // Build result object.
    $result = new FeedsParserResult();
    $result->title = 'Import facts';
    $result->description = 'Import facts from XML file';

    // Run through items
    foreach ($xml->item as $item) {
      $data = array();
      $data['title'] = (string)$item->title;
      $data['body'] = (string)$item->body;
      $data['source'] = (string)$item->sourcename;
      $data['sourcelink'] = (string)$item->sourcelink;
      $data['inspirename'] = (string)$item->inspirename;      
      $data['inspirelink'] = (string)$item->inspirelink;
      $data['author'] = (string)$item->author;
      $data['orgnization'] = (string)$item->org;
      $data['tags'] = array((string)$item->subject1, (string)$item->subject2, (string)$item->subject3, (string)$item->subject4);
      $data['unixtime'] = (string)$item->unixtime;
      
      $result->items[] = $data;
    }
    
    return $result;
  }

  public function getMappingSources() {
    $fields = array(
      'title', 
      'body', 
      'source', 
      'sourcelink', 
      'inspirename', 
      'inspirelink', 
      'author', 
      'orgnization',
      'tags',
      'unixtime',
    );
    $mapping = array();
    foreach ($fields as $field) {
      $mapping[$field] = array(
        'name' => ucfirst($field),
        'description' => ucfirst($field),
      );
    }
    $mapping += parent::getMappingSources();
    return $mapping;
  }
}