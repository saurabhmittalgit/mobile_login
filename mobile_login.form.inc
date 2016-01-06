<?php

/**
 * @file
 * Mobile login user forms.inc
 */

/**
 * Implements hook_form().
 */
function mobile_login_udpate_username_form($form, $form_state) {
  $mobile_login_config = variable_get('mobile_login_config');

  $form['update_login_username'] = array(
    '#type' => 'container',
    '#title' => t('Update Username'),
  );
  $form['update_login_username']['old_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Old Username'),
    '#required' => TRUE,
    '#description' => t('Enter your old username.'),
  );
  $form['update_login_username']['pass'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#required' => TRUE,
    '#description' => t('Enter your password.'),
  );
  $form['update_login_username']['new_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Number'),
    '#required' => TRUE,
    '#maxlength' => $mobile_login_config['mobile_user_login']['login_name_field_maxlength'],
    '#description' => t('Enter your mobile number, to make it as your login username.'),
  );
  $form['update_login_username']['user_email'] = array(
    '#type' => 'hidden',
    '#value' => arg(2),
  );
  $form['update_login_username']['md5'] = array(
    '#type' => 'hidden',
    '#value' => arg(3),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );

  return $form;
}

/**
 * Implements hook_form_submit().
 */
function mobile_login_udpate_username_form_validate($form, $form_state) {
  if (!empty($form_state['values']['old_username']) && !empty($form_state['values']['pass']) && !empty($form_state['values']['new_username'])) {
    // Validate calling URL params.
    if (md5($form_state['values']['user_email'] . $form_state['values']['old_username']) != $form_state['values']['md5']) {
      form_set_error('', t('Please enter corrent details.'));
    }
    // Validate new username to be mobile number.
    elseif (!is_numeric($form_state['values']['new_username'])) {
      form_set_error('new_username', t('Please enter valid mobile number.'));
    }
    // validate username is avaialble or not.
    elseif (user_load_by_name($form_state['values']['new_username'])) {
      form_set_error('new_username', t('This mobile number is already registered.'));
    }
    elseif (!user_authenticate($form_state['values']['old_username'], trim($form_state['values']['pass']))) {
      form_set_error('', t('User authentication failed, Please enter corrent username and password.'));
    }
  }
}

/**
 * Implements hook_form_submit().
 */
function mobile_login_udpate_username_form_submit($form, $form_state) {
  $account = user_load_by_name($form_state['values']['old_username']);
  if (!empty($account)) {
    // Update username.
    $account->name = $form_state['values']['new_username'];
    user_save($account);

    drupal_set_message('Username updated successfully.');
  }
  else {
    drupal_set_message(t('Invalid Username'), 'error');
  }
}
