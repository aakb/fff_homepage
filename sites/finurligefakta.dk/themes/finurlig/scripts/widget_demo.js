var fffWidgetConfig = [];

(function ($) {
  "use strict";

  $(document).ready(function() {
    $('#generator select[name="type"]').change( function() {
      refreshWidget(false);
    });
    $('#generator select[name="style"]').change( function() {
      refreshWidget(false);
    });
    $('#generator input[name="color"]').change( function() {
      refreshWidget(false);
    });
    $('#generator input[name="crate_link"]').change( function() {
      refreshWidget(false);
    });
    refreshWidget(true);
  });

  function refreshWidget( initial ) {
    if ($('#widget').html && !initial) {
      $('#widget').html('');
      var css = document.getElementsByTagName('link');
      if (css !== undefined && css.length) {
        css[css.length - 1].disabled = true;
      }
    }

    var type = $('#generator select[name="type"]').val();
    var style = $('#generator select[name="style"]').val();
    var color = $('#generator input[name="color"]:checked').val();
    var create = $('#generator input[name="crate_link"]:checked').val();

    fffWidgetConfig = [];
    fffWidgetConfig.push({
      'widget' : type,
      'target' : '#widget',
      'style' : {
        'type' : style,
        'color' : color
      },
      'tracking' : false,
      'button' : { 'reload' : true, 'create' : (create === undefined ? false : true) },
      'event' : { 'loadComplet' : null }
    });
    (function() {
      var fff = document.createElement('script'); fff.type = 'text/javascript'; fff.async = true;
      fff.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + 'service.finurligefakta.dk/widgets/fff.widget.min.js';
      var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(fff, s);
    })();
  }
}(jQuery));
