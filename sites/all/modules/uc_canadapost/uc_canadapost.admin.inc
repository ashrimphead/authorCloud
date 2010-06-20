<?php
// $Id: uc_canadapost.admin.inc,v 1.1 2009/03/18 05:03:29 tr Exp $

/**
 * @file
 * Canada Post module administration menu callbacks
 *
 */


/**
 * Canada Post shipping settings
 *
 * Configures Canada Post CPC ID, available services, and other settings
 * related to shipping quotes.
 */
function uc_canadapost_admin_settings() {
  $form = array();

  $form['uc_canadapost_cpcid'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Canada Post merchant CPC ID'),
    '#default_value' => variable_get('uc_canadapost_cpcid', 'CPC_DEMO_XML'),
    '#required'      => TRUE,
    '#description'   => t('Your Canada Post SellOnline account number. Visit http://sellonline.canadapost.ca to get one.'),
  );
  $form['uc_canadapost_url'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Canada Post interface URL'),
    '#default_value' => variable_get('uc_canadapost_url', 'http://sellonline.canadapost.ca:30000/'),
    '#required'      => TRUE,
    '#description'   => t('The server and port to use for shipping calculations.'),
  );
  $form['uc_canadapost_services'] = array(
    '#type'          => 'checkboxes',
    '#title'         => t('Canada Post Services'),
    '#default_value' => variable_get('uc_canadapost_services', _uc_canadapost_service_list()),
    '#options'       => _uc_canadapost_service_list(),
    '#description'   => t('Select the shipping services that are available to customers. This list only serves to further restrict the services as set up in your SellOnline account. If you have not selected a service in your Canada Post account, it will not show up even if it is selected here.'),
  );
  $form['uc_canadapost_markup_type'] = array(
    '#type'          => 'select',
    '#title'         => t('Markup type'),
    '#default_value' => variable_get('uc_canadapost_markup_type', 'percentage'),
    '#options'       => array(
      'percentage' => t('Percentage (%)'),
      'multiplier' => t('Multiplier (×)'),
      'currency'   => t('Addition (!currency)', array('!currency' => variable_get('uc_currency_sign', '$'))),
    ),
  );
  $form['uc_canadapost_markup'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Shipping rate markup'),
    '#default_value' => variable_get('uc_canadapost_markup', '0'),
    '#description'   => t('Markup shipping rate quote by dollar amount, percentage, or multiplier. Please note if this rate is not blank, it overrides the "Handling fee" set up in your SellOnline account. If blank, the handling fee from your SellOnline account will be used.'),
  );
  $form['uc_canadapost_turnaround'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Turn-around time'),
    '#default_value' => variable_get('uc_canadapost_turnaround', '24'),
    '#description'   => t('Number of hours for turn-around time before shipping. Allows rates to properly calculate extra charges for weekend delivery. Overrides the setting in your SellOnline account.'),
  );
  $form['uc_canadapost_datefmt'] = array(
    '#type'          => 'select',
    '#title'         => t('Delivery date format'),
    '#default_value' => variable_get('uc_canadapost_datefmt', ''),
    '#description'   => t('Format to display estimated delivery date.'),
    '#options'       => _uc_canadapost_get_date_options(),
  );

  $orig = variable_get('uc_quote_store_default_address', new stdClass());
  $form['uc_canadapost_postalcode'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Ship from postal code'),
    '#default_value' => variable_get('uc_canadapost_postalcode', isset($orig->postal_code) ? $orig->postal_code : ''),
    '#description'   => t('Postal code to ship from. If supplied, overrides the entry in your SellOnline account.'),
  );

  return system_settings_form($form);
}
