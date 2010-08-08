<?php
// $Id: udashboard.user.inc,v 1.1 2009/05/03 07:56:56 lelizondob Exp $

/**
 * @file
 * Callback to show the user admin page
 */

/**
 * udashboard user admin page
 * 
 * @return the user_admin page
 */
function udashboard_user_admin() {	
	// load the users help message and display the user page
	$usermsg = variable_get('udashboard_usersmsg', '');
	$output = '<p>';
  $output .= check_plain($usermsg);
	$output .= '</p>';
	
	include_once(drupal_get_path('module', 'user') . '/user.admin.inc');
	$output .= user_admin();
	return $output;
}