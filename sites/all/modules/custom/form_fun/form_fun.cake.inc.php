<?php

/*
 * Page callback
 */
function form_fun_cake_page() {
	return drupal_get_form('form_fun_cake');
}

/*
 * To create form
 */
function form_fun_cake($form, &$form_state) {
	//$form = array();
	//单选框
	$form['choice'] = array(
		'#type' => 'select',
		'#title' => t('Cake or pie?'),
		'#description' => t('Would you like cake or pie?'),
		'#options' => array(
			'cake' => t('Cake please'),
			'pie' => t('Pie I guess'),
		),
		'#default_value' => 'cake',
		'#required' => TRUE,
	);
	//提交按钮
	$form['buttons']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Submit'),
	);
	$form['buttons']['unsure'] = array(
		'#type' => 'submit',
		'#value' => t('Equivocate'),
		'#submit' => array('form_fun_cake_unsure'), //其他处理
		'#validate' => array(), //其他验证
	);
	
	return $form;
}


/*
 * To validate form
 */
function form_fun_cake_validate(&$form, &$form_state) {
	//dsm($form_state);
	if($form_state['values']['choice'] == 'cake') {
		form_set_error('choice',t('we are out of cake.'));
	}
}

/*
 * To submit form
 */
function form_fun_cake_submit(&$form, &$form_state) {
	dsm($form_state['values']);
	$form_state['redirect'] = '';//''就是首页
}

/*
 * Customed submit function
 */
function form_fun_cake_unsure(&$form, &$form_state) {
	drupal_set_message( t('Make up your mind.'),'warning');
}


