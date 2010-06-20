<?php

/**
 * Implementation of hook_content_default_fields().
 */
function authorcloud_settings_content_default_fields() {
  module_load_include('inc', 'authorcloud_settings', 'authorcloud_settings.defaults');
  $args = func_get_args();
  return call_user_func_array('_authorcloud_settings_content_default_fields', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function authorcloud_settings_imagecache_default_presets() {
  module_load_include('inc', 'authorcloud_settings', 'authorcloud_settings.defaults');
  $args = func_get_args();
  return call_user_func_array('_authorcloud_settings_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_node_info().
 */
function authorcloud_settings_node_info() {
  module_load_include('inc', 'authorcloud_settings', 'authorcloud_settings.features.node');
  $args = func_get_args();
  return call_user_func_array('_authorcloud_settings_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function authorcloud_settings_user_default_permissions() {
  module_load_include('inc', 'authorcloud_settings', 'authorcloud_settings.defaults');
  $args = func_get_args();
  return call_user_func_array('_authorcloud_settings_user_default_permissions', $args);
}
