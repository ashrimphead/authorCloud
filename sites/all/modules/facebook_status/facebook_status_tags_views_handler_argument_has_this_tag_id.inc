<?php
// $Id$

/**
 * @file
 *   Allow only statuses with a specific tag.
 */

/**
 * Argument handler to select statuses containing a specific tag.
 */
class facebook_status_tags_views_handler_argument_has_this_tag_id extends views_handler_argument_numeric {
  function option_definition() {
    $options = parent::option_definition();
    $options['facebook_status_tags_type'] = array(
      'default' => array(),
      'translatable' => FALSE,
    );
    return $options;
  }
  function options_form(&$form, &$form_state) {
    $options = parent::options_form($form, $form_state);
    $opt = array('user' => t('Users'));
    if (module_exists('taxonomy')) {
      $opt['term'] = t('Terms');
    }
    $options = $this->options;
    $form['warning'] = array(
      '#value' => t('Warning: this argument can be slow.'),
      '#weight' => -100,
    );
    $form['facebook_status_tags_type'] = array(
      '#title' => t('Tag types'),
      '#type'  => 'checkboxes',
      '#required' => TRUE,
      '#options' => $opt,
      '#default_value' => $options['facebook_status_tags_type'],
    );
  }
  function query() {
    $this->ensure_my_table();
    if (!empty($this->options['break_phrase'])) {
      views_break_phrase($this->argument, $this);
    }
    else {
      $this->value = array($this->argument);
    }
    $where = '';
    $options = $this->options['facebook_status_tags_type'];
    if (count($options) > 0) {
      $where .= " AND (type = '";
      $types = array();
      foreach ($options as $type => $val) {
        if ($val) {
          $types[] = $type;
        }
      }
      $where .= implode("' OR type = '", $types) ."')";
    }
    if (count($this->value) > 1) {
      $operator = empty($this->options['not']) ? 'IN' : 'NOT IN';
      $placeholders = implode(', ', array_fill(0, sizeof($this->value), '%d'));
      $query = "$this->table_alias.$this->real_field IN (SELECT sid FROM {facebook_status_tags} WHERE rid $operator ($placeholders) $where)";
      $this->query->add_where(0, db_prefix_tables($query), $this->value);
    }
    else {
      $operator = empty($this->options['not']) ? '=' : '!=';
      $query = "$this->table_alias.$this->real_field IN (SELECT sid FROM {facebook_status_tags} WHERE rid $operator %d $where)";
      $this->query->add_where(0, db_prefix_tables($query), $this->argument);
    }
  }
  function default_actions($which = NULL) {
    $defaults = parent::default_actions($which);
    unset($defaults['summary asc']);
    unset($defaults['summary desc']);
    return $defaults;
  }
}