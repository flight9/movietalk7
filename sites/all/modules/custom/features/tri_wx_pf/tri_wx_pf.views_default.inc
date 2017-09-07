<?php
/**
 * @file
 * tri_wx_pf.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tri_wx_pf_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_list_with_wechat';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User List With Wechat';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User List With Wechat';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'status' => 'status',
    'uid' => 'uid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: User: Wechat User */
  $handler->display->display_options['relationships']['wechat_login_user']['id'] = 'wechat_login_user';
  $handler->display->display_options['relationships']['wechat_login_user']['table'] = 'users';
  $handler->display->display_options['relationships']['wechat_login_user']['field'] = 'wechat_login_user';
  $handler->display->display_options['relationships']['wechat_login_user']['required'] = TRUE;
  /* Field: Bulk operations: Wechat User */
  $handler->display->display_options['fields']['views_bulk_operations_1']['id'] = 'views_bulk_operations_1';
  $handler->display->display_options['fields']['views_bulk_operations_1']['table'] = 'views_entity_tri_wechat_user';
  $handler->display->display_options['fields']['views_bulk_operations_1']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations_1']['relationship'] = 'wechat_login_user';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['row_clickable'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_operations'] = array(
    'action::tri_wechat_register_approve_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::tri_wechat_register_deny_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Field: User: Mobile */
  $handler->display->display_options['fields']['field_mobile']['id'] = 'field_mobile';
  $handler->display->display_options['fields']['field_mobile']['table'] = 'field_data_field_mobile';
  $handler->display->display_options['fields']['field_mobile']['field'] = 'field_mobile';
  /* Field: Wechat User: Headimgurl */
  $handler->display->display_options['fields']['headimgurl']['id'] = 'headimgurl';
  $handler->display->display_options['fields']['headimgurl']['table'] = 'wechat_login_user';
  $handler->display->display_options['fields']['headimgurl']['field'] = 'headimgurl';
  $handler->display->display_options['fields']['headimgurl']['relationship'] = 'wechat_login_user';
  $handler->display->display_options['fields']['headimgurl']['label'] = 'Head Img';
  $handler->display->display_options['fields']['headimgurl']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['headimgurl']['alter']['text'] = '<img width="100px" height="100px" src="[headimgurl]"/>';
  $handler->display->display_options['fields']['headimgurl']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['headimgurl']['alter']['path'] = '[headimgurl]';
  /* Field: Wechat User: Openid */
  $handler->display->display_options['fields']['openid']['id'] = 'openid';
  $handler->display->display_options['fields']['openid']['table'] = 'wechat_login_user';
  $handler->display->display_options['fields']['openid']['field'] = 'openid';
  $handler->display->display_options['fields']['openid']['relationship'] = 'wechat_login_user';
  /* Field: Wechat User: User link type */
  $handler->display->display_options['fields']['user_link_type']['id'] = 'user_link_type';
  $handler->display->display_options['fields']['user_link_type']['table'] = 'wechat_login_user';
  $handler->display->display_options['fields']['user_link_type']['field'] = 'user_link_type';
  $handler->display->display_options['fields']['user_link_type']['relationship'] = 'wechat_login_user';
  /* Field: Wechat User: Nickname */
  $handler->display->display_options['fields']['nickname']['id'] = 'nickname';
  $handler->display->display_options['fields']['nickname']['table'] = 'wechat_login_user';
  $handler->display->display_options['fields']['nickname']['field'] = 'nickname';
  $handler->display->display_options['fields']['nickname']['relationship'] = 'wechat_login_user';
  /* Field: Wechat User: Sex */
  $handler->display->display_options['fields']['sex']['id'] = 'sex';
  $handler->display->display_options['fields']['sex']['table'] = 'wechat_login_user';
  $handler->display->display_options['fields']['sex']['field'] = 'sex';
  $handler->display->display_options['fields']['sex']['relationship'] = 'wechat_login_user';
  $handler->display->display_options['fields']['sex']['separator'] = '';
  /* Field: Wechat User: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'wechat_login_user';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['relationship'] = 'wechat_login_user';
  /* Field: Wechat User: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'wechat_login_user';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['relationship'] = 'wechat_login_user';
  /* Field: Wechat User: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'wechat_login_user';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['relationship'] = 'wechat_login_user';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user-list-with-wechat';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'User list with wechat';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['user_list_with_wechat'] = $view;

  return $export;
}
