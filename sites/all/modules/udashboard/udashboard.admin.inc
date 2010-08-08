<?php
// $Id: udashboard.admin.inc,v 1.2 2009/05/03 18:09:53 lelizondob Exp $

/**
 * @file
 * Admin page callbacks for the udashboard module.
 */

/**
 * Menu callback argument. Creates the udashboard administration form.
 *
 * TODO: Add better help messages by default. Can't think of anything right now. Patches welcome.
 */
function udashboard_admin() {
	
	// I don't wanna make User Dashboard so dependent from other modules so we just disable some funcionality. Maybe in 2.x I'll do it another way.
	
	// we check if popups it's enabled or not
	if(module_exists('popups')) {
		$popups_enabled = FALSE;
	}
	else {
		$popups_enabled = TRUE;
		drupal_set_message(t("You don't have the Popups Module installed, if you want to use Popups to add content, go to http://drupal.org/project/popups and install the module."));
	}
	
	// we check if views it's installed or not	
	if(module_exists('views')) {
		$views_enabled = FALSE;
	}
	else {
		$views_enabled = TRUE;
		drupal_set_message(t("You don't have the Views Module installed, if you want to use Views, go to http://drupal.org/project/views and install the module."));
	}
	
  $form['udashboard_welcomemsg'] = array(
    '#title' => t('My Dashboard Welcome Message'),
    '#description' => t('You can write a custom message to the user here. This message will show up on the tracker page.'),
    '#type' => 'textarea',
    '#size' => 6,
    '#default_value' => variable_get('udashboard_welcomemsg', t("What it's up?")),
    '#required' => FALSE,
  );
  $form['udashboard_tracker'] = array(
  	'#title' => t('Tracker Options'),
  	'#type' => fieldset,
  );
  $form['udashboard_tracker']['udashboard_definetracker'] = array(
		// TODO: Make this more user fiendly and disable Views or Tracker options if they are not installed. Patches welcome.
    '#title' => t('Tracker to use'),
    '#description' => t('Select if you want to use the Views tracker or Tracker2.'),
    '#type' => 'radios',
    '#options' => array(t('Views Tracker'), t('Tracker2')),
    '#default_value' => variable_get('udashboard_definetracker', '0'),
    '#required' => TRUE,
  );
  $form['udashboard_tracker']['udashboard_defineviews_tracker'] = array(
    '#title' => t('Tracker view name'),
    '#description' => t('If you set the previous option to Views Tracker, you can type the name of the view to use.'),
    '#type' => 'textfield',
    '#size' => 15,
		'#disabled' => $views_enabled,
    '#default_value' => variable_get('udashboard_defineviews_tracker', 'viewstracker'),
    '#required' => FALSE,
  );
  $form['udashboard_comments'] = array(
  	'#title' => t('Comment Options'),
  	'#type' => fieldset,
  );
  $form['udashboard_comments']['udashboard_commentsmsg'] = array(
    '#title' => t('Comments Help Message'),
    '#description' => t('You can write a custom message to the user here.'),
    '#type' => 'textarea',
    '#size' => 6,
    '#default_value' => variable_get('udashboard_commentsmsg', t("This are the comments in the site")),
    '#required' => FALSE,
  );
  $form['udashboard_comments']['udashboard_definecomments'] = array(
		// TODO: Make this more user fiendly and disable Use Views Comments if Views it's not installed. Patches welcome.
    '#title' => t('Comments to use'),
    '#description' => t('Select the page to show to administer comments. If you change this option you have to clear the cache.'),
    '#type' => 'radios',
    '#options' => array(t('Simple. Use Views Comments'), t('Advanced. Use Drupal Comments'), t('Hide Comments')),
    '#default_value' => variable_get('udashboard_definecomments', '0'),
    '#required' => TRUE,
  );
  $form['udashboard_comments']['udashboard_defineviews_comments'] = array(
    '#title' => t('Comments view name'),
    '#description' => t('If you set the previous option to Simple Views Comments, you can type the name of the view to use.'),
    '#type' => 'textfield',
    '#size' => 15,
		'#disabled' => $views_enabled,
    '#default_value' => variable_get('udashboard_defineviews_comments', 'comments'),
    '#required' => FALSE,
  );
  $form['udashboard_nodeaddpage'] = array(
  	'#title' => t('Node Add Page Options'),
  	'#type' => fieldset,
  );
  $form['udashboard_nodeaddpage']['udashboard_nodeaddmsg'] = array(
    '#title' => t('Users Area Help Message'),
    '#description' => t('You can write a custom message to the user here.'),
    '#type' => 'textarea',
    '#size' => 6,
    '#default_value' => variable_get('udashboard_nodeaddmsg', t("Select one of the options below, after you click on one of them you will be taken to a page where you will have to fill a form to create content.")),
    '#required' => FALSE,
  );
	$form['udashboard_nodeaddpage']['udashboard_usepopups'] = array(
		'#title' => t('Use Popups for Adding Content'),
		'#type' => radios,
		'#options' => array(t('No'), t('Yes')),
		'#default_value' => variable_get('udashboard_usepopups', '0'),
    '#required' => FALSE,
		'#disabled' => $popups_enabled,
		'#description' => t('You can use Popups to add content if you want to.'),
	);
  $form['udashboard_nodeaddpage']['udashboard_showdescription'] = array(
    '#title' => t('Show description of content types on node add page?'),
    '#description' => t('You can hide the content types description on node add page.'),
    '#type' => 'radios',
    '#options' => array(t('Show description'), t('Hide description')),
    '#default_value' => variable_get('udashboard_showdescription', '0'),
    '#required' => FALSE,
  );
  $form['udashboard_users'] = array(
  	'#title' => t('Users Area Options'),
  	'#type' => fieldset,
  );
  $form['udashboard_users']['udashboard_usersmsg'] = array(
    '#title' => t('Users Area Help Message'),
    '#description' => t('You can write a custom message to the user here.'),
    '#type' => 'textarea',
    '#size' => 6,
    '#default_value' => variable_get('udashboard_usersmsg', t("This are the users in the site")),
    '#required' => FALSE,
  );

  return system_settings_form($form);
}

/**
 * Validate callback.
 */
function udashboard_admin_validate($form, &$form_state) {
	$trackercase = $form_state['values']['udashboard_definetracker'];
  if($trackercase == 0) {
  	if(!module_exists('views')) {
	  	form_set_error('udashboard_definetracker', t("Views it's not installed. Please install it."));
	  }
  }
  elseif($trackercase == 1) {
  	if(!module_exists('tracker2')) {
	  	form_set_error('udashboard_definetracker', t("Tracker2 it's not installed. Please install it."));
	  }
  }
  else {
  	
  }
}