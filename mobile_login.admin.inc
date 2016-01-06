<?php

/**
 * @file
 * Mobile login admin config file.
 */

/**
 * Implements hook_form().
 */
function mobile_login_configuration_form($form, $form_state) {
  $default_values = variable_get('mobile_login_config');

  $form['mobile_login_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mobile number login settings'),
    '#tree' => TRUE,
  );
  $form['mobile_login_config']['force_mobile_login'] = array(
    '#type' => 'checkbox',
    '#title' => t('Force mobile login'),
    '#description' => t('Force user to login only by mobile number.'),
    '#default_value' => isset($default_values['force_mobile_login']) ? $default_values['force_mobile_login'] : 0,
  );
  $form['mobile_login_config']['allowed_non_mobile_login_username'] = array(
    '#type' => 'textarea',
    '#title' => t('Allowed non mobile usernames'),
    '#description' => t('Enter comma seprated Non mobile login usernames, allowed them to login via their previous username.'),
    '#default_value' => isset($default_values['allowed_non_mobile_login_username']) ? $default_values['allowed_non_mobile_login_username'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="mobile_login_config[force_mobile_login]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['mobile_login_config']['mobile_user_login'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Login Settings'),
    '#collapsible' => TRUE,
  );
  $form['mobile_login_config']['mobile_user_login']['login_name_field_label'] = array(
    '#type' => 'textfield',
    '#title' => t('User Login username field label'),
    '#description' => t('User Login username field label.'),
    '#required' => TRUE,
    '#default_value' => isset($default_values['mobile_user_login']['login_name_field_label']) ? $default_values['mobile_user_login']['login_name_field_label'] : t('Username'),
  );
  $form['mobile_login_config']['mobile_user_login']['login_name_field_maxlength'] = array(
    '#type' => 'textfield',
    '#title' => t('Login username field maxlength'),
    '#description' => t('User Login username field allowed maxlength.'),
    '#required' => TRUE,
    '#default_value' => isset($default_values['mobile_user_login']['login_name_field_maxlength']) ? $default_values['mobile_user_login']['login_name_field_maxlength'] : 10,
  );
  $form['mobile_login_config']['mobile_user_login']['login_name_field_description'] = array(
    '#type' => 'textarea',
    '#title' => t('User Login username field description'),
    '#description' => t('User Login username field description.'),
    '#default_value' => isset($default_values['mobile_user_login']['login_name_field_description']) ? $default_values['mobile_user_login']['login_name_field_description'] : '',
  );

  $form['mobile_login_config']['mobile_register_user'] = array(
    '#type' => 'fieldset',
    '#title' => t('Register New User Settings'),
    '#collapsible' => TRUE,
  );
  $form['mobile_login_config']['mobile_register_user']['username_lable'] = array(
    '#type' => 'textfield',
    '#title' => t('User name field label'),
    '#description' => t('User name field label.'),
    '#required' => 1,
    '#default_value' => isset($default_values['mobile_register_user']['username_lable']) ? $default_values['mobile_register_user']['username_lable'] : t('Username'),
  );
  $form['mobile_login_config']['mobile_register_user']['username_description'] = array(
    '#type' => 'textarea',
    '#title' => t('User name field description'),
    '#description' => t('User name field description.'),
    '#default_value' => isset($default_values['mobile_register_user']['username_description']) ? $default_values['mobile_register_user']['username_description'] : '',
  );

  $form['mobile_login_config']['forget_password'] = array(
    '#type' => 'fieldset',
    '#title' => t('Forget User Password Settings'),
    '#collapsible' => TRUE,
  );
  $form['mobile_login_config']['forget_password']['username_lable'] = array(
    '#type' => 'textfield',
    '#title' => t('User name field label'),
    '#description' => t('User name field label.'),
    '#default_value' => isset($default_values['forget_password']['username_lable']) ? $default_values['forget_password']['username_lable'] : t('Username'),
  );

  $form['mobile_login_config']['mobile_bulk_update_notification'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mobile number bulk update email notification'),
    '#collapsible' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="mobile_login_config[force_mobile_login]"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['mobile_login_config']['mobile_bulk_update_notification']['force_send_email_to_change_username'] = array(
    '#type' => 'checkbox',
    '#title' => t('Force send email to change user login name'),
    '#description' => t('If checked, System will send email to all non mobile number login users to change their username.'),
    '#default_value' => isset($default_values['mobile_bulk_update_notification']['force_send_email_to_change_username']) ? $default_values['mobile_bulk_update_notification']['force_send_email_to_change_username'] : 0,
  );
  $form['mobile_login_config']['mobile_bulk_update_notification']['email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Force update username email subject'),
    '#description' => t('Force update login username to mobile number email subject.'),
    '#default_value' => isset($default_values['mobile_bulk_update_notification']['email_subject']) ? $default_values['mobile_bulk_update_notification']['email_subject'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="mobile_login_config[mobile_bulk_update_notification][force_send_email_to_change_username]"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['mobile_login_config']['mobile_bulk_update_notification']['email_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Force update username email message'),
    '#description' => t('Force update login username to mobile number email message.<br >You can use <b>@update-link</b> placeholder to replace with update link url.'),
    '#default_value' => isset($default_values['mobile_bulk_update_notification']['email_body']) ? $default_values['mobile_bulk_update_notification']['email_body'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="mobile_login_config[mobile_bulk_update_notification][force_send_email_to_change_username]"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['mobile_login_config']['mobile_bulk_update_notification']['send_thankyou_after_update'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send Thankyou mail after update username.'),
    '#description' => t('If checked, System will send email to user after successful update on their username.'),
    '#default_value' => isset($default_values['mobile_bulk_update_notification']['send_thankyou_after_update']) ? $default_values['mobile_bulk_update_notification']['send_thankyou_after_update'] : 0,
    '#states' => array(
      'visible' => array(
        ':input[name="mobile_login_config[mobile_bulk_update_notification][force_send_email_to_change_username]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['mobile_login_config']['mobile_update_thankyou'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mobile number update thankyou notification'),
    '#collapsible' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="mobile_login_config[mobile_bulk_update_notification][send_thankyou_after_update]"]' => array('checked' => TRUE),
        ':input[name="mobile_login_config[mobile_bulk_update_notification][force_send_email_to_change_username]"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['mobile_login_config']['mobile_update_thankyou']['email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Thank you email subject'),
    '#description' => t('After updating username thank you email subject.'),
    '#required' => TRUE,
    '#default_value' => isset($default_values['mobile_update_thankyou']['email_subject']) ? $default_values['mobile_update_thankyou']['email_subject'] : '',
  );
  $form['mobile_login_config']['mobile_update_thankyou']['email_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Thank you email message'),
    '#description' => t('After updating username thank you email message.'),
    '#required' => TRUE,
    '#default_value' => isset($default_values['mobile_update_thankyou']['email_body']) ? $default_values['mobile_update_thankyou']['email_body'] : '',
  );

  // Additional submit callback.
  $form['#submit'][] = 'mobile_login_configuration_submit_callback';

  return system_settings_form($form);
}

/**
 * Implements hook_form_validate().
 */
function mobile_login_configuration_form_validate(&$form, &$form_state) {
  // If force mobile login selected.
  if ($form_state['values']['mobile_login_config']['force_mobile_login']) {

    // Check for current administor user exists in non mobile login users.
    if (!_is_current_admin_user_is_allowed_without_mobile_login($form_state['values']['mobile_login_config']['allowed_non_mobile_login_username'])) {
      form_set_error('allowed_non_mobile_login_username', t('Enter atleast your username, otherwise you will not be able to log in.'));
    }
  }
}

/**
 * Additional submit callback to send email to all non mobile login user to change their user name.
 */
function mobile_login_configuration_submit_callback(&$form, &$form_state) {
  // If force send email to non mobile No. users.
  if ($form_state['values']['mobile_login_config']['force_mobile_login'] && $form_state['values']['mobile_login_config']['mobile_bulk_update_notification']['force_send_email_to_change_username']) {
    // Setting a batch process to send email.

    $batch = array(
      'title' => t('Processing batch items to send notification ...'),
      'operations' => array(),
      'finished' => 'user_mobile_login_force_update_finished',
      'init_message' => t('Initializing...'),
      'progress_message' => t('Processing batch @current out of @total.'),
      'error_message' => t('System encountered an error.'),
      'file' => drupal_get_path('module', 'mobile_login') . '/mobile_login.admin.inc',
    );

    $batch['operations'][] = array(
      'user_mobile_login_force_update_notification_batch_process', array()
    );
    batch_set($batch);
  }
}

/**
 * Prcess batch items.
 */
function user_mobile_login_force_update_notification_batch_process(&$context) {
  $limit = 1;

  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_user'] = variable_get('force_update_notification_processed_uid', 0);
  }

  // Fetching notification email data.
  $email_config = variable_get('mobile_login_config');
  $email_subject = $email_config['mobile_bulk_update_notification']['email_subject'];
  $email_body = $email_config['mobile_bulk_update_notification']['email_body'];

  // With each pass through the callback, retrieve the next group of uids.
  $result = db_query("SELECT uid,mail FROM {users} WHERE name not REGEXP '^[0-9]' AND uid NOT IN (0) AND uid > " . $context['sandbox']['current_user'] . " ORDER BY uid ASC limit 0, $limit")->fetchAll();

  if (!empty($result)) {
    foreach ($result as $record) {
      // Send notification to user.
      send_force_login_update_email_notification($record->mail, $email_subject, $email_body);
    }

    // Update our progress information.
    $context['sandbox']['progress'] ++;
    $context['sandbox']['current_user'] = $record->uid;

    // Set last processed user id.
    variable_set('force_update_notification_processed_uid', $record->uid);

    // Recursion, to process other unprocessed users.
    user_mobile_login_force_update_notification_batch_process($context);
  }
}

/**
 *  Batch process finished message.
 */
function user_mobile_login_force_update_finished() {
  drupal_set_message('Force update login to mobile number email notification sent.');
}

/**
 * Check whether administor user is allowed, with out mobile number.
 */
function _is_current_admin_user_is_allowed_without_mobile_login($allowed_users) {
  global $user;
  $allowed_user_names = explode(',', $allowed_users);

  if (is_numeric($user->name) || in_array($user->name, $allowed_user_names)) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Send force udpate login username email.
 */
function send_force_login_update_email_notification($email, $subject, $body) {
  global $language;

  $placeholders = array(
    '@update-link' => _mobile_login_update_notification_link($email),
  );

  drupal_mail('mobile_login', 'force-update-login', $email, $language->language, array(
    'subject' => $subject,
    'body' => format_string($body, $placeholders),
    )
  );
}

/**
 * Get link for update user login to mobile Number login.
 */
function _mobile_login_update_notification_link($email) {
  global $base_url;

  $account = user_load_by_mail($email);
  $md5_param = $email . $account->name;

  return $base_url . '/user/update-username/' . $email . '/' . md5($md5_param);
}
