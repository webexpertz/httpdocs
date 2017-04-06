<?php
/**
 * @file
 * rmets_cpd_reviews_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rmets_cpd_reviews_features_default_rules_configuration() {
  $items = array();
  $items['rules_cpd_review_review_application_awaiting_review'] = entity_import('rules_config', '{ "rules_cpd_review_review_application_awaiting_review" : {
      "LABEL" : "CPD Review - review application awaiting review",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "rmets_cpd_reviews" ],
      "REQUIRES" : [ "rules", "rmets_cpd_reviews" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cpd_report_review" : "cpd_report_review" } }
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
        { "drupal_message" : { "message" : "An email has been sent to the reviewers." } },
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-reviews" ] },
            "ITEM" : { "review" : "Review" },
            "DO" : [
              { "mail" : {
                  "to" : [ "review:field-reviewer:mail" ],
                  "subject" : "There is a member\\u0027s CPD Report ready for you to review.",
                  "message" : "Dear [review:field-reviewer:field-forenames] [review:field-reviewer:field-surname]\\r\\n\\r\\nThere is a member\\u0027s CPD Report ready for you to review.  Click the link below to go straight to it. You may have to log in first.\\r\\n\\r\\n\\u003Ca href=\\u0022[site:url]cpd\\/review\\/report\\/[node:nid]\\u0022\\u003EReview\\u003C\\/a\\u003E\\r\\n\\r\\nRemember that you can save your comments and return to the application up until you mark it as either \\u2018Reviewed acceptable\\u2019 or \\u2018Reviewed Unacceptable\\u2019, at which point the RMetS administrator will be notified that the review is complete.\\r\\n\\r\\nIf you have any questions about the review process please email accreditation@rmets.org.\\r\\n\\r\\nKind regards,\\r\\n\\r\\nThe Royal Meteorological Society",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_cpd_review_review_application_reviews_complete'] = entity_import('rules_config', '{ "rules_cpd_review_review_application_reviews_complete" : {
      "LABEL" : "CPD Review - review application reviews complete",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "rmets_cpd_reviews" ],
      "REQUIRES" : [ "rules", "rmets_cpd_reviews" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cpd_report_review" : "cpd_report_review" } }
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
            "subject" : "A CPD Report has been reviewed and is ready for processing.",
            "message" : "A CPD Report has been reviewed and is ready for processing.\\r\\n\\r\\nFor details, \\u003Ca href=\\u0022[node:edit-url]\\u0022\\u003Eclick on the link below\\u003C\\/a\\u003E",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_cpd_review_review_application_submit_edit_content'] = entity_import('rules_config', '{ "rules_cpd_review_review_application_submit_edit_content" : {
      "LABEL" : "CPD Review - review application submit (edit content)",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "rmets_cpd_reviews" ],
      "REQUIRES" : [ "rules", "rmets_cpd_reviews" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cpd_report_review" : "cpd_report_review" } }
          }
        },
        { "rules_condition_workflow_state" : {
            "workflow_state_id" : [ "node:field-status" ],
            "workflow_label" : "Pending"
          }
        },
        { "rules_condition_workflow_state" : {
            "workflow_state_id" : [ "node-unchanged:field-status" ],
            "workflow_label" : "Draft"
          }
        }
      ],
      "DO" : [
        { "component_rules_cpd_review_send_review_application_submit_email" : { "node" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_cpd_review_review_application_submit_new_content'] = entity_import('rules_config', '{ "rules_cpd_review_review_application_submit_new_content" : {
      "LABEL" : "CPD Review - review application submit (new content)",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "rmets_cpd_reviews" ],
      "REQUIRES" : [ "rules", "rmets_cpd_reviews" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cpd_report_review" : "cpd_report_review" } }
          }
        },
        { "rules_condition_workflow_state" : {
            "workflow_state_id" : [ "node:field-status" ],
            "workflow_label" : "Pending"
          }
        }
      ],
      "DO" : [
        { "component_rules_cpd_review_send_review_application_submit_email" : { "node" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_cpd_review_send_review_application_submit_email'] = entity_import('rules_config', '{ "rules_cpd_review_send_review_application_submit_email" : {
      "LABEL" : "CPD Review - send review application submit email",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
      "ACTION SET" : [
        { "drupal_message" : { "message" : "Thank you for submitting your CPD Report.  An administrator has been informed and reviewers will now be assigned." } },
        { "mail" : {
            "to" : "\\u003Caccreditation@rmets.org\\u003E,\\u003Cadministrator@rmets.org\\u003E",
            "subject" : "A CPD Report has been submitted by [node:field-user:field-forenames] [node:field-user:field-surname].",
            "message" : "A CPD Report has been submitted by [node:field-user:field-forenames] [node:field-user:field-surname].\\r\\n\\r\\nFor details, \\u003Ca href=\\u0022[node:edit-url]\\u0022\\u003Eclick on the link below\\u003C\\/a\\u003E",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_rmets_cpd_review_reminder'] = entity_import('rules_config', '{ "rules_rmets_cpd_review_reminder" : {
      "LABEL" : "Send CPD review email reminder",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "rmets_cpd_reviews" ],
      "REQUIRES" : [ "rules", "rmets_cpd_reviews" ],
      "ON" : [ "rmets_cpd_reviews_user_review_due_reminder" ],
      "DO" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "CPD Review Reminder",
            "message" : "Dear [user:field-forenames] [user:field-surname],\\r\\n\\r\\nYour next CPD Report is due for submission before [user:field-cpd-report-submission-date:long_date_no_time] in order to maintain your current accreditation held with the society.\\r\\n\\r\\nFor details of the process please read the following web page on the Society\\u2019s website: http:\\/\\/www.rmets.org\\/accsys\\r\\n\\r\\nKind regards,\\r\\n\\r\\nThe Royal Meteorological Society",
            "from" : "[site:mail]",
            "language" : [ "" ]
          }
        },
        { "data_set" : { "data" : [ "user:field_last_cpd_rep_remind_date" ], "value" : "now" } }
      ]
    }
  }');
  return $items;
}
