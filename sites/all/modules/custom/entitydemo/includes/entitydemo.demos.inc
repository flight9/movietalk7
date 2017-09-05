<?php

function entitydeomo_demos() {
	$links = array();

	// We just loop through everything in the module's hook_menu implementation
	// and print that list here.
	$items = entitydemo_menu();
	unset($items['entidemo']);
	foreach ($items as $url => $item) {
	$links[] = l($item['title'], $url) . ' : ' . $item['description'];
	}

	if (empty($links)) {
	$links[] = t('Doesn\'t look like any demos have been setup yet.');
	}

	return theme('item_list', array('items' => $links));
}





