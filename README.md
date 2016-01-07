# mobile_login
Description
-----------
This module provides the functionality to change login username with
 mobile number on to the site. You can also configure force mobile mobile for user
along with the send email notification to each non mobile user to update their username.

Requirements
------------
Drupal 7.x

Installation
------------
* Install as usual, see http://drupal.org/node/70151 for further information.

Configuration
------------
* After successful module installation, Go to mobile login configuration link.

Here you can configure below settings.
1. Force mobile login,
    ** If you want to allow only mobile number login on your site, check this option.
    Now user can only be login by only their mobile number.

2. Allowed non mobile usernames
    ** place comma separated usernames that you want to allow with old username.

3. User login form username field label, allowed max length and descriptions.

4. Register new user form username field label, allowed max length and descriptions.

5. Forget password form username field label, allowed max length and descriptions.

6. Force Update Email notification.
    ** If you want to sent email notification to update username to mobile, check this option.
    This will sent email notification to all non mobile login users aling with unique
    update link. You can also configure this email subject and message.
7. Sent Thank you email after successful update of username to mobile number.
    ** Check this option to sent thank you email notification when user successfully 
    updated their username to mobile number. Here you can also configure thankyou
    email subject and message.


CREDITS
-------

The idea came up from no module providing change username to mobile number
 login along with configurable email notification.

Current maintainers:
* Saurabh Mittal () - https://www.drupal.org/u/mittalsaurabh
