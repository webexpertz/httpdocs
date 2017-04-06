jQuery(document).ready(function() {


function megaHoverOver(){
  jQuery('div.sub').hide();

  jQuery(this).children('div.sub').css({'opacity':'1', 'display':'block', 'z-index':1000, 'position':'absolute', 'left':'0px' });
  jQuery(this).addClass('hover-state');
  jQuery(this).addClass('expanded');
  jQuery(this).removeClass('collapsed');

jQuery.fn.calcSubWidth = function() {
rowWidth = 0;
//Calculate row
jQuery(this).find(".Rcol").each(function() {
  biggestRow = 0;
  rowWidth = jQuery(this).width();
  if(rowWidth > biggestRow) {
    biggestRow += rowWidth;
  }
});
return biggestRow;
};
jQuery(this).find(".sub").show();
}

function megaHoverOut() {
  jQuery(this).removeClass('hover-state');
  jQuery(this).removeClass('expanded');
  jQuery(this).addClass('collapsed');
  jQuery(this).find(".sub").hide();	
}

var config = {
  sensitivity: 2, // number = sensitivity threshold (must be 1 or higher)
  interval: 100, // number = milliseconds for onMouseOver polling interval
  over: megaHoverOver, // function = onMouseOver callback (REQUIRED)
  timeout: 500, // number = milliseconds delay before onMouseOut
  out: megaHoverOut // function = onMouseOut callback (REQUIRED)
}

if (jQuery('.primary-nav').css('z-index') == 490) {
  jQuery("ul#main-menu li .sub").css({'opacity':'1'});
  jQuery("ul#main-menu > li").hoverIntent(config);
}
  jQuery("div.sub").hide();
  jQuery("ul#main-menu > li").addClass('collapsed');

  // JQuery bgiframe stops select elements coming through the menu on ie6.
  jQuery('div.sub').bgiframe({opacity: false, src:'about:blank'});
});
