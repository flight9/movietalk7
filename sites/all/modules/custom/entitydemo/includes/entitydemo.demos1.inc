<?php

function entitydeomo_page1() {
	$id = 5;
	$type = 'node';
	
	$entity = entity_load($type, array($id));
	#dsm($entity);
	$entity = reset($entity);//取数组[0]
	dsm($entity);
	
	list($id,$vid,$bundle) = entity_extract_ids($type,$entity);
	dsm($id);
	dsm($vid);
	dsm($bundle);
	
	return 'hello world';
}




