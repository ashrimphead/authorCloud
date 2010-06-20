<?php
// $Id: og_subgroups.admin.inc,v 1.7 2008/09/03 08:04:43 amitaibu Exp $

/**
 * @file
 * Admin page callbacks for the subgroups for organic groups module.
 */

/**
 * Builds and returns the subgroups settings form.
 */
function og_subgroups_admin_settings() {
  $form['propagte_content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Group posts propagation'),
    '#description' => t('Content can be propagated through the subgroups tree.'),
    '#collapsible' => TRUE,
  );
  $form['propagte_content']['og_subgroups_propagate_content'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content propagation'),
    '#description' => t('Set the propagation type for posts which are group posts. Select in which direction the propagation should occur. For example if you select "Parents" content will propagate up the tree.'),
    '#options' => array(
      'up' => t('Parents'),
      'down' => t('Children'),
      'side' => t('Siblings'),
    ),
    '#default_value' => variable_get('og_subgroups_propagate_content', array()),
  );
  $form['propagte_user'] = array(
    '#type' => 'fieldset',
    '#title' => t('Users propagation'),
    '#description' => t('Group members and admins can be propagated through the subgroups tree.'),
    '#collapsible' => TRUE,
  );
  // Member propagation.
  $form['propagte_user']['og_subgroups_propagate_member'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Propagation direction'),
    '#description' => t('Set the propagation type for group members.'),
    '#options' => array(
      'up' => t('Parents'),
      'down' => t('Children'),
      'side' => t('Siblings'),
    ),
    '#default_value' => variable_get('og_subgroups_propagate_member', array()),
  );
  // Propagation type.
  $form['propagte_user']['og_subgroups_propagate_type'] = array(
    '#type' => 'radios',
    '#title' => t('Admins propagation'),
    '#description' => t('Propagate admin rights. The propagation will be in the direction defined in "Propagation direction".'),
    '#options' => array(
      'no_admin_propagate' => t("Don't propagate admin rights, only membership"),  
      'admin_propagate' => t('Propagate admin rights and membership as well'),      
      'only_admin_propagate' => t("Propagate only admin rights, don't propagate membership"),
    ),
    '#default_value' => variable_get('og_subgroups_propagate_type', 'admin_propagate'),
  );  
  $form['propagte_user']['og_subgroups_propagate_demote'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Rights demotion'),
    '#description' => t("Determine if a demotion action should occur along the subgroups. 
      Demotion referes to removing admin and to completely unsubscribing a member/ admin from a group.
      These options will be executed only if the 'Members propagation' is set."),
    '#options' => array(
      'remove_admin' => t('Propagate removal of admin rights (user still remains a member)'),
      'unsubscribe' => t('Unsubscribe or deny membership of a member'),

    ),
    '#default_value' => variable_get('og_subgroups_propagate_demote', array()),
  );  

  return system_settings_form($form);
}