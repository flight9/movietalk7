<?php

/*
 * 产生页面的 callback
 */
function menu_magic_extra($wildcard){
	$content = array(
		'#type'	=> 'markup',
		'#markup' => '<p>'. t('This wildcard contains the value "%wildcard".', array('%wildcard' => $wildcard)). '</p>',
	);
	return $content;
}




