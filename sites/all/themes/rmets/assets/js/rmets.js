/* Javascript */

/* Contents:

  #01# - Basics

  #READY# - Document ready
*/


/* #01# - Basics */


/* #READY# - Document ready */

(function ($) {
    $(document).ready(function () {
    // Hackery to remove event dates
        var seen = {};
        $('.event-search-date').each(function () {
            var txt = $(this).text();
            if (seen[txt]) {
                $(this).remove();
            } else {
                seen[txt] = true;
            }
        });

        var seen = {};
        $('.cal-block').each(function () {
            var txt = $(this).attr('class');
            if (seen[txt]) {
                $(this).remove();
            } else {
                seen[txt] = true;
            }
        });

    //Carousel
	    if ($('.carousel-content').length > 0) {
		$('.carousel-content').prepend('<a id="caro-prev" class="arrow previous" href="#">Previous</a>');
		$('.carousel-content').append('<a id="caro-next" class="arrow next" href="#">Next</a>');

		$('.view-homepage-carousel .view-content').append('<div id="nav" class="carousel-tabs"><ul></ul></div>');


		$(".carousel-content ul").carouFredSel({
			    scroll: {
				    fx: "scroll",
				    pauseOnHover: true,
				    duration: 1500
			    },
			    prev: {
				    button: "#caro-prev",
				    key: "left"
		    },
			    next: {
				    button: "#caro-next",
				    key: "right"
			    },
			    pagination: {
				    container: "#nav ul",
				    anchorBuilder: function (nr) {
					return '<li class="tab-' + nr + '"></li>';
				    }
			    }
		}, {
		    classnames: {
			selected: "active",
			hidden: "hidden",
			disabled: "disabled",
			paused: "paused",
			stopped: "stopped"
		    }
		});

		$(".caroufredsel_wrapper").width(621);
		$(".overlay").each(function (index, domEle) {
		    var id = index - 1;
		    if (id === -1) {
			id = 3;
		    }
		    $("#nav li:eq(" + (id)  + ")").html($(this).html());
		});
		$("#nav li:last").addClass('last');
	    }

    // CPD Accreditation view - change file links.
    if ($('#node_cpd_accreditation_application_full_group_education_prof_training').length > 0 || $('.page-cpd-review-record').length > 0) {
      $('.field-name-field-file-attachment .file a').each(function() {
        $(this).unbind('click').click(function(event) {
          event.preventDefault();
          event.stopPropagation();
          window.open(this.href, '_blank');
        });
      });
    }

		if ($('.collapseable-table').length > 0) {
			$('.collapseable-table').each(function() {
				var tableElement = $(this);
				var matches = tableElement.attr('id').match(/event-schedule-([a-z0-9\-]+)/);
				var sessionId = matches[1];
				$('#event-schedule-link-' + sessionId).unbind('click').click(function() {
					if ($('#event-schedule-link-' + sessionId + ' span').text().toLowerCase() == 'show') {
						$('#event-schedule-link-' + sessionId + ' span').text('Hide');
					}	else {
						$('#event-schedule-link-' + sessionId + ' span').text('Show');
					}
					tableElement.toggleClass('open');
				});
			});
		}
  });

    function onAfter() {
        $('.carousel-content li').show();
    }
})(jQuery);
