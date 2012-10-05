var fffWidgetConfig = [];

(function ($) {

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
    refreshWidget(true);
  });

  function refreshWidget( initial ) {
    console.log($('#widget').html);
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
  
    fffWidgetConfig = [];
    fffWidgetConfig.push({
      'widget' : type,
      'target' : '#widget',
      'style' : {
        'type' : style,
        'color' : color
      },
      'tracking' : false,
      'button' : { 'reload' : true },
      'event' : { 'loadComplet' : null }
    });
    (function() {
      var fff = document.createElement('script'); fff.type = 'text/javascript'; fff.async = true;
      fff.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + 'service.finurligefakta.dk/widgets/fff.widget.min.js';  
      var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(fff, s);
    })();
  }

}(jQuery));
