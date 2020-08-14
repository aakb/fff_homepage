<?php

/**
 * Implements hook_preprocess_page().
 *
 * Addes JavaScript for the header widget or the demo script if we are on that
 * page.
 */
function finurlig_preprocess_page(&$variables) {
	// Assuming that page of type page is always the widget demo page
	if (isset($variables['node']) && $variables['node']->nid == 1058) {
	  drupal_add_js(drupal_get_path('theme', 'finurlig') .'/scripts/widget_demo.min.js', 'file');
	} else {
	  drupal_add_js(drupal_get_path('theme', 'finurlig') .'/scripts/fff_widget.js', 'file');
	}
}

/**
 * Implements theme_links().
 *
 * Changes the main manu to use anchors, as this is a single page site.
 *
 */
function finurlig_links($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  global $base_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';

    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
           && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        /*
         * Make link anchor link if main menu.
         *
         * @todo: clean up and use l().
         *
         */
        if (isset($attributes['class'][2]) && $attributes['class'][2] == 'main-menu') {
          $link['href'] = $base_url . '#' . str_replace('/', '-', $link['href']);
          $output .= '<a href="' . $link['href'] . '">' . $link['title'] . '</a>';
        }
        else {
          // Pass in $link as $options, they share the same keys.
          $output .= l($link['title'], $link['href'], $link);
        }
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

/**
 * Implements hook_js_alter().
 */
function finurlig_js_alter(&$javascript) {

}


/**
 * Implements hook_preprocess_html_tag().
 */
function finurlig_preprocess_html_tag(&$vars) {
  // Change html tags to apply cookie information.
  if ($vars['element']['#tag'] == 'script') {
    // Add consent check to google analytics.
    if (strpos($vars['element']['#attributes']['src'], 'google_analytics/googleanalytics.js')) {
      $src = $vars['element']['#attributes']['src'];
      $vars['element']['#attributes']['data-consent-src'] = $src;
      $vars['element']['#attributes']['src'] = '';
      $vars['element']['#attributes']['data-category-consent'] = 'cookie_cat_statistic';
    }

    // Add consent check to google analytics inline script.
    if (strpos($vars['element']['#value'], 'GoogleAnalyticsObject')) {
      $value = $vars['element']['#value'];
      $vars['element']['#value'] = "window.addEventListener('CookieInformationConsentGiven', function (event) { 
if (CookieInformation.getConsentGivenFor('cookie_cat_statistic')) {" . $value . "} 
}, false);";
    }
  }
}
