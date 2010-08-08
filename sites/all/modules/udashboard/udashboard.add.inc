<?php
// $Id: udashboard.add.inc,v 1.2 2009/05/05 21:04:25 lelizondob Exp $

/**
 * @file
 * Shows a nice "create content page"
 * 
 * Most of the code is from http://drupal.org/project/createcontentblock
 */

/**
 * This is just the node/add page with a custom message at the top
 *
 * If popups module it's enabled, we can make use of it
 * TODO: Add some cool icons to make it more user fiendly
 */

function udashboard_node_add_page() {
  global $user;
  $types = node_get_types();
  $showdescription = variable_get('udashboard_showdescription', '');
	
	$usepopups = variable_get('udashboard_usepopups', '');
	// if popups is installed we call it!
	
	if (module_exists('popups')) {
		popups_add_popups();
	}
	
  foreach ($types as $type) {
    if (node_access('create', $type->type)) {
      $typestring = str_replace('_', '-', $type->type);
      $node_title_link = drupal_ucfirst($type->name);
      
			if (module_exists('popups') && $usepopups == 1) {
				$typeoutput = '<dt>'. l($node_title_link, "node/add/$typestring", array('attributes'=>array('class' => 'popups-form-noupdate'))) .'</dt>';				
			}
			else {
				$typeoutput = '<dt>'. l($node_title_link, "node/add/$typestring") .'</dt>';
			}
			
      if ($showdescription == 0) {
      	$typeoutput .= '<dd>'. filter_xss_admin($type->description) .'</dd>';	
      }
      $item[$type->type] = $typeoutput;
    }
  }
  // load the udashboard_nodeaddmsg variable with the help message
  $nodeaddmsg = variable_get('udashboard_nodeaddmsg', '');
  if (isset($item)) {
    $output = '<h3>' . t('What do you want to create?') . '</h3>'
    . '<p>' . check_plain($nodeaddmsg) . '</p>'
    . '<dl>'. implode('', $item) .'</dl>';
  }
  else {
    $output = t('No content types available.');
  }
  return $output;
}
