<?php
/**
 * @file
 * rmets_cpd_accreditation_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rmets_cpd_accreditation_features_default_rules_configuration() {
  $items = array();
  $items['rules_cpd_accreditation_review_application_awaiting_review'] = entity_import('rules_config', '{ "rules_cpd_accreditation_review_application_awaiting_review" : {
      "LABEL" : "CPD Accreditation - review application awaiting review",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "2",
      "TAGS" : [ "rmets_cpd_accredditation" ],
      "REQUIRES" : [ "rules", "rmets_cpd_reviews" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cpd_accreditation_application" : "cpd_accreditation_application" } }
          }
        },
        { "rules_condition_workflow_state" : {
            "workflow_state_id" : [ "node:field-status" ],
            "workflow_label" : "Awaiting review"
          }
        },
        { "NOT rules_condition_workflow_state" : {
            "workflow_state_id" : [ "node-unchanged:field-status" ],
            "workflow_label" : "Awaiting review"
          }
        }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-reviews" ] },
            "ITEM" : { "review" : "Review" },
            "DO" : [
              { "drupal_message" : { "message" : "An email has been sent to reviewer [review:field-reviewer:name] ([review:field-reviewer:mail])" } },
              { "mail" : {
                  "to" : [ "review:field-reviewer:mail" ],
                  "subject" : "There is a member\\u0027s accreditation application ready for you to review.",
                  "message" : "Dear [review:field-reviewer:field-forenames] [review:field-reviewer:field-surname]\\r\\n\\r\\nThere is an application ready for you to review.  Click the link below to go straight to it. You may have to log in first.\\r\\n\\r\\n\\u003Ca href=\\u0022[site:url]cpd\\/review\\/application\\/[node:nid]\\u0022\\u003EReview\\u003C\\/a\\u003E\\r\\n\\r\\nRemember that you can save your comments and return to the application up until you mark it as either \\u2018Reviewed acceptable\\u2019 or \\u2018Reviewed Unacceptable\\u2019, at which point the RMetS administrator will be notified that the review is complete.\\r\\n\\r\\nIf you have any questions about the review process please email accreditation@rmets.org.\\r\\n\\r\\nKind regards,\\r\\n\\r\\nThe Royal Meteorological Society",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_cpd_accreditation_review_application_payment_complete'] = entity_import('rules_config', '{ "rules_cpd_accreditation_review_application_payment_complete" : {
      "LABEL" : "CPD Accreditation - review application payment complete",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "TAGS" : [ "rmets_cpd_accredditation" ],
      "REQUIRES" : [ "rules", "rmets_cpd_reviews" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cpd_accreditation_application" : "cpd_accreditation_application" } }
          }
        },
        { "rules_condition_workflow_state" : {
            "workflow_state_id" : [ "node:field-status" ],
            "workflow_label" : "Pending"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field_user:mail" ],
            "subject" : "Your accreditation application has been paid for and is now being processed.",
            "message" : "Dear [node:field-user:field-forenames] [node:field-user:field-surname],\\r\\n\\r\\nYour payment of has been received.  Your application is now being processed.\\r\\n\\r\\nYou can view the status of your application at any time by clicking on the link below to the Royal Meteorological Society Website. If you are not already logged into the website, you will be asked to login: \\u003Ca href=\\u0022[node:url]\\u0022\\u003Eview application\\u003C\\/a\\u003E\\r\\n\\r\\nThe Accreditation Board will arrange to take up references from the referees you quote, and to evaluate the qualifications and experience you have shown. We will contact you again as soon as we have heard back from your referees.\\r\\n\\r\\nIf you need to make any amendments to your application or if you have any questions you must contact the Society by email at accreditation@rmets.org or by telephone on +44 (0)118 9568500\\r\\n\\r\\nKind regards,\\r\\n\\r\\nAccreditation Officer\\r\\nThe Royal Meteorological Society",
            "language" : [ "" ]
          }
        },
        { "drupal_message" : { "message" : "An email has been sent to [node:field-user:mail]" } }
      ]
    }
  }');
  $items['rules_cpd_accreditation_review_application_reviews_complete'] = entity_import('rules_config', '{ "rules_cpd_accreditation_review_application_reviews_complete" : {
      "LABEL" : "CPD Accreditation - review application reviews complete",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "3",
      "TAGS" : [ "rmets_cpd_accredditation" ],
      "REQUIRES" : [ "rules", "rmets_cpd_reviews" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cpd_accreditation_application" : "cpd_accreditation_application" } }
          }
        },
        { "rules_condition_workflow_state" : {
            "workflow_state_id" : [ "node:field-status" ],
            "workflow_label" : "Review processing"
          }
        },
        { "rules_condition_workflow_state" : {
            "workflow_state_id" : [ "node-unchanged:field-status" ],
            "workflow_label" : "Awaiting review"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "\\u003Caccreditation@rmets.org\\u003E,\\u003Cadministrator@rmets.org\\u003E",
            "subject" : "An Accreditation Application has been reviewed and is ready for processing.",
            "message" : "The accreditation application from [node:field-full-name] has been reviewed by all the reviewers and is ready for processing.\\r\\n\\r\\nFor details, \\u003Ca href=\\u0022[node:edit-url]\\u0022\\u003Eclick on the link below\\u003C\\/a\\u003E",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_cpd_accreditation_review_application_submit_edit_content'] = entity_import('rules_config', '{ "rules_cpd_accreditation_review_application_submit_edit_content" : {
      "LABEL" : "CPD Accreditation - review application submit (edit content)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-1",
      "TAGS" : [ "rmets_cpd_accredditation" ],
      "REQUIRES" : [ "rules", "rmets_cpd_reviews" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "AND" : [
            { "node_is_of_type" : {
                "node" : [ "node" ],
                "type" : { "value" : { "cpd_accreditation_application" : "cpd_accreditation_application" } }
              }
            },
            { "rules_condition_workflow_state" : {
                "workflow_state_id" : [ "node:field-status" ],
                "workflow_label" : "Pending"
              }
            },
            { "OR" : [
                { "rules_condition_workflow_state" : {
                    "workflow_state_id" : [ "node-unchanged:field-status" ],
                    "workflow_label" : "Draft"
                  }
                },
                { "rules_condition_workflow_state" : {
                    "workflow_state_id" : [ "node-unchanged:field-status" ],
                    "workflow_label" : "Awaiting payment"
                  }
                }
              ]
            }
          ]
        }
      ],
      "DO" : [
        { "component_rules_cpd_accreditation_send_review_application_submit_email" : { "node" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_cpd_accreditation_review_application_submit_new_content'] = entity_import('rules_config', '{ "rules_cpd_accreditation_review_application_submit_new_content" : {
      "LABEL" : "CPD Accreditation - review application submit (new content)",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "rmets_cpd_accredditation" ],
      "REQUIRES" : [ "rules", "rmets_cpd_reviews" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cpd_accreditation_application" : "cpd_accreditation_application" } }
          }
        },
        { "rules_condition_workflow_state" : {
            "workflow_state_id" : [ "node:field-status" ],
            "workflow_label" : "Pending"
          }
        }
      ],
      "DO" : [
        { "component_rules_cpd_accreditation_send_review_application_submit_email" : { "node" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_cpd_accreditation_review_application_successful'] = entity_import('rules_config', '{ "rules_cpd_accreditation_review_application_successful" : {
      "LABEL" : "CPD Accreditation - review application successful",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "TAGS" : [ "rmets_cpd_accredditation" ],
      "REQUIRES" : [ "rules", "rmets_cpd_reviews" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cpd_accreditation_application" : "cpd_accreditation_application" } }
          }
        },
        { "rules_condition_workflow_state" : {
            "workflow_state_id" : [ "node:field-status" ],
            "workflow_label" : "Acceptable"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field_user:mail" ],
            "subject" : "Your Accreditation Application has been Accepted",
            "message" : "Dear [node:author:field-forenames] [node:author:field-surname],\\r\\n\\r\\nI am pleased to inform you that your accreditation has now been is confirmed.  You may now use the post-nominal in your professional activities. Your certificate will be sent in the post to you as soon as possible.\\r\\n\\r\\nTo maintain your accreditation status you must maintain a record of your Continuous Professional Development (CPD) which is to be submitted, when requested by the Society.  Failure to do so or the completion of inadequate CPD records will result in the cancellation of your accreditation and the withdrawal of your right to use the post nominal.  Details of the process by which you can apply for dormancy are available in the Professional Accreditation area of the Society\\u2019s website.\\r\\n\\r\\nOnce again, I would like to offer you the congratulations of Council on achieving this status.  We have endeavoured to set a high but fair standard for the qualification, and trust that you will maintain and enhance the reputation of the Society and of the science and its applications by your contributions.\\r\\n\\r\\nIf you have any questions please do not hesitate to contact accreditation@rmets.org\\r\\n\\r\\nRegards\\r\\nThe Royal Meteorological Society",
            "from" : [ "" ],
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_cpd_accreditation_send_review_application_submit_email'] = entity_import('rules_config', '{ "rules_cpd_accreditation_send_review_application_submit_email" : {
      "LABEL" : "CPD Accreditation - send review application submit email",
      "PLUGIN" : "action set",
      "TAGS" : [ "rmets_cpd_accredditation" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
      "ACTION SET" : [
        { "drupal_message" : { "message" : "Thank you for submitting your accreditation application.  An administrator has been informed and reviewers will now be assigned to your application." } },
        { "mail" : {
            "to" : "\\u003Caccreditation@rmets.org\\u003E,\\u003Cadministrator@rmets.org\\u003E",
            "subject" : "An Accreditation Application has been submitted by [node:field-full-name]",
            "message" : "An accreditation application has been submitted by [node:field-full-name]. For details, \\u003Ca href=\\u0022[node:url]\\u0022\\u003Eclick the link below\\u003C\\/a\\u003E",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_redirect_user_back_to_accreditation_node_after_paying'] = entity_import('rules_config', '{ "rules_redirect_user_back_to_accreditation_node_after_paying" : {
      "LABEL" : "Redirect user back to Accreditation node after paying",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "TAGS" : [ "rmets_cpd_accredditation" ],
      "REQUIRES" : [ "rmets_cpd_accreditation", "commerce_order", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "IF" : [
        { "rmets_cpd_commerce_order_contains_accreditation_product" : { "commerce_order" : [ "commerce_order" ] } }
      ],
      "DO" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "completed" } },
        { "rmets_cpd_accreditation_go_back_to_accreditation_in_order" : { "account" : [ "commerce-order" ] } }
      ]
    }
  }');
  $items['rules_rmets_processed_cpd_accreditation_application'] = entity_import('rules_config', '{ "rules_rmets_processed_cpd_accreditation_application" : {
      "LABEL" : "Update accreditation after paying",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "rmets_cpd_accredditation" ],
      "REQUIRES" : [ "rmets_cpd_accreditation", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "IF" : [
        { "rmets_cpd_commerce_order_contains_accreditation_product" : { "commerce_order" : [ "commerce_order" ] } }
      ],
      "DO" : [
        { "rmets_cpd_accreditation_update_from_order" : { "account" : [ "commerce-order" ] } }
      ]
    }
  }');
  $items['rules_send_cpd_accreditation_email_reminder'] = entity_import('rules_config', '{ "rules_send_cpd_accreditation_email_reminder" : {
      "LABEL" : "Send CPD accreditation email reminder",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "rmets_cpd_accredditation" ],
      "REQUIRES" : [ "rules", "rmets_cpd_accreditation" ],
      "ON" : [ "rmets_cpd_accreditation_user_review_due_reminder" ],
      "DO" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "CPD Accreditation Reminder",
            "message" : "Dear [user:field-forenames] [user:field-surname],\\r\\n\\r\\nYour next CPD Application is due for submission before [user:field-next-cpd-submission-date:long_date_no_time] in order to maintain your current accreditation held with the society.\\r\\n\\r\\nFor details of the process please read the following web page on the Society\\u2019s website: http:\\/\\/www.rmets.org\\/accsys\\r\\n\\r\\nKind regards,\\r\\n\\r\\nThe Royal Meteorological Society",
            "from" : "accreditation@rmets.org",
            "language" : [ "" ]
          }
        },
        { "data_set" : { "data" : [ "user:field-last-cpd-reminder-date" ], "value" : "now" } }
      ]
    }
  }');
  return $items;
}
