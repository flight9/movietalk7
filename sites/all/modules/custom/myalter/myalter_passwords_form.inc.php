<?php

/*
 * Settings form for blacklisting passwords
 */
function myalter_passwords_form($form, &$form_state) {
	$form['myalter_badpasswords'] = array(
		'#type' => 'textfield',
		'#title' => t('Bad passwords'),
		'#description' => t('Enter a list of "bad passwords" seperated by commas. If a user tries to enter of them either on account creation or when editing his account, the form will display an error message.'),
		'#default_value' => variable_get('myalter_badpasswords','password,1234,hello'),//后面是默认值
		'#required' => TRUE,
	);
	return system_settings_form($form);
}




