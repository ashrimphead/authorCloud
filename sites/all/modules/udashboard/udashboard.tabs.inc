<?php
// $Id: udashboard.tabs.inc,v 1.1 2009/05/03 07:56:56 lelizondob Exp $

/**
 * @file
 * Callbacks to show the tabs defined in dashboard.admin.inc
 */

/**
 * The main page for the module, the tracker. 
 * 
 * @return a page containing the tracker
 */
function udashboard_viewstracker() {
	// display the Welcome message
	global $user;
  $account = user_load(array('name' => $user->name));
  $welcomemsg = variable_get('udashboard_welcomemsg', '');
  $output = t('Hi @user. ', array('@user' => $account->name));
  $output .= check_plain($welcomemsg);
  
	// we define the cases
	$trackercase = variable_get('udashboard_definetracker', '');
	
	// first case, when using views
	if($trackercase == 0) {
		if(module_exists('views')) {
			// we get the name of the view
			$name = variable_get('udashboard_defineviews_tracker', '');
			$output .= views_embed_view($name, $display_id = 'default');
		}
	}
	
	// second case, when using tracker2
	if($trackercase == 1) {
		if(module_exists('tracker2')) {
			// we just call tracker2 tracker2_page()
			include_once(drupal_get_path('module', 'tracker2') . '/tracker2.pages.inc');
			$output .= tracker2_page();	
		}
	}
	
	return $output;
}

/**
 * The comments udashboard page. 
 * 
 * @return a page containing comments
 */
function udashboard_comments() {
	// define the cases
	$commentcase = variable_get('udashboard_definecomments', '');
	
	// load the comments help message and display
	$commentmsg = variable_get('udashboard_commentsmsg', '');
	$output = '<p>';
  $output .= check_plain($commentmsg);
	$output .= '</p>';
	
	// first case, when using views
	if($commentcase == 0) {
		$name = variable_get('udashboard_defineviews_comments', '');
		$output .= views_embed_view($name, $display_id = 'default');
	}
	
	// second case, when using drupal comments admin page
	if($commentcase == 1) {
		include_once(drupal_get_path('module', 'comment') . '/comment.admin.inc');
		$output .= comment_admin();
	}
	
	// third case, hide the comments
	if($commentcase == 2) {
		$output = t("You shouldn't be able to see this page and it's tab. Please clear the drupal cache and the tab will dissapear.");
	}	
	
	return $output;
}


// To add your own view to the udashboard Module
// create your view and then take this code as an example
/*
function udashboard_myview() {
	$name = 'yourviewname';
	// you could also change the 'default' display to something like 'page' or 'block'
	$output = views_embed_view($name, $display_id = 'default');
}
*/

// Then, add the Menu
/*
$items['udashboard/myview'] = array(
    'title' => 'My View',
    'description' => 'Some description here.',
    'page callback' => 'udashboard_myview',
    'page arguments' => array('list'),
    'access arguments' => array('access content'),
    'type' => MENU_LOCAL_TASK,
    'weight' => 5,
  );
*/