<?php

/*
 * To create form
 */
function form_fun_tree($form, &$form_state) {
	//按树分组
	$form['#tree'] = TRUE;
	//Fieldset
	$form['home'] = array(
		'#type' => 'fieldset',
		'#title' => t('Home address'),
	);
	$form['home']['street'] = array(
		'#type' => 'textfield',
		'#title' => t('Street address'),
	);
	$form['home']['city'] = array(
		'#type' => 'textfield',
		'#title' => t('City'),
	);
	//Fieldset
	$form['work'] = array(
		'#type' => 'fieldset',
		'#title' => t('Work address'),
	);
	$form['work']['street'] = array(
		'#type' => 'textfield',
		'#title' => t('Street address'),
	);
	$form['work']['city'] = array(
		'#type' => 'textfield',
		'#title' => t('City'),
	);
	//Button
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Submit'),
	);
	
	return $form;
}

/*
 * To submit form
 */
function form_fun_tree_submit(&$form, &$form_state) {
	dsm($form_state);
}



