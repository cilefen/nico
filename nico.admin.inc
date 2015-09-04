<?php

/**
 * Generates the nico blog editing form.
 */
function nico_blog_form($form, &$form_state, $nico_blog, $op = 'edit', $entity_type = NULL) {

  if ($op == 'clone') {
    // Only label is provided for cloned entities.
    $nico_blog->label .= ' (cloned)';
    $nico_blog->type = $entity_type . '_clone';
  }

  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => isset($nico_blog->title) ? $nico_blog->title : '',
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save blog'),
    '#weight' => 40,
  );
  return $form;
}

/**
 * Form API submit callback for the admin form.
 */
function nico_blog_form_submit(&$form, &$form_state) {
  $nico_blog = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $nico_blog->save();
  $form_state['redirect'] = 'admin/structure/nico';
}
