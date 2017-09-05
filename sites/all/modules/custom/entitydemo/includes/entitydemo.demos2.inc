<?php

function entitydeomo_page2() {
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node');
	$result = $query->execute();
	#dsm($result);
	
	$query = new EntityFieldQuery();
	$query->fieldCondition('field_year','value', 2016,'>=');
	$result = $query->execute();
	#dsm($result);
	
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type','node')
		->propertyCondition('promote', 1);
	$result = $query->execute();
	#dsm($result);
	
	if (isset($result['node'])) {
		$nids = array_keys($result['node']);
		$items = entity_load('node', $nids);
	} 
	#dsm($items);
	
	dpm(entity_get_info()); //gets a list of all defined entities
	dpm(field_info_fields()); //gets a list of all defined fields	

	
	return 'This is a demo page.';
}




