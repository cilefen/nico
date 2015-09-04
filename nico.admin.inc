<?php

/**
 * The nico blog editing form.
 */
function nico_blog_form($form, &$form_state, $nico_blog, $op, $entity_type = NULL) {

  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => isset($nico_blog->title) ? $nico_blog->title : '',
    '#weight' => -10,
  );
  field_attach_form('nico_blog', $nico_blog, $form, $form_state);
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save blog'),
    '#weight' => 40,
  );
  return $form;
}

/**
 * Submit callback for the editing form.
 */
function nico_blog_form_submit(&$form, &$form_state) {
  global $user;
  $nico_blog = entity_ui_form_submit_build_entity($form, $form_state);
  $nico_blog->uid = $user->uid;
  $nico_blog->created = isset($nico_blog->created) ? $nico_blog->created : REQUEST_TIME;
  $nico_blog->changed = REQUEST_TIME;
  $nico_blog->save();
  $form_state['redirect'] = 'admin/structure/nico';
}
