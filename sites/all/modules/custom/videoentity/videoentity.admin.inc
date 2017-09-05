<?php

/*
 * Form for adding/editing a video entity
 */
function video_form($form, &$form_state, $video=NULL) {
	$form['name'] = array(
		'#title' => t('Name'),
		'#type' => 'textfield',
		'#default_value' => isset($video->name)? $video->name:'', //for Edit
		'#description' => t('Video title'),
		'#required' => true,
		'#weight' => -50,
	);
	
	$form['embedcode'] = array(
		'#title' => t('Embed code'),
		'#type' => 'textfield',
		'#default_value' => isset($video->embedcode)? $video->embedcode:'',
		'#description' => t('Embed code from youtube.com'),
		'#required' => true,
	);
	
	$form['duration'] = array(
		'#title' => t('Duration'),
		'#type' => 'textfield',
		'#default_value' => isset($video->duration)? $video->duration:'',
		'#description' => t('Duration of the video in seconds.'),
		'#required' => true,
	);
	
	//这个是动态的(不是固定的)
	field_attach_form('video', $video, $form, $form_state);
	
	$form['action'] = array(
		'#type' => 'actions',
		'submit' => array(
			'#type' => 'submit',
			'#value' => isset($video->id)? t('Update video asset'):t('Save video asset'),
		),
	);
	
	return $form;
} 

/*
 * Validate handler for video entity form
 */
function video_form_validate($form, &$form_state) {
	if(isset($form_state['values']['duration']) && !is_numeric($form_state['values']['duration'])) {
		form_set_error('duration',t('Duration field must be an integer value.'));
	}
}

/*
 * Submit handler for video entity form
 */
function video_form_submit($form, &$form_state) {
	$video = entity_ui_form_submit_build_entity($form, $form_state);
	$video->save();
	drupal_set_message(t('@name video has been saved.',array('@name' => $video->name)));
	$form_state['redirect'] = 'admin/videoentity';
}



