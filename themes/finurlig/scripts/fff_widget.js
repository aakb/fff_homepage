function fffWidgetCompleted() {
  
}

var fffWidgetConfig = [];
fffWidgetConfig.push({
  'widget' : 'interactive',
  'target' : '#fff-widget',
  'event' : {
    'loadComplet' : function () {
      (function($) {
        $('.fffW-widget').append('<div class="fff-quotes"></div>');
      }(jQuery));
    }
  }
});

(function() {
  "use strict";
  
  var fff = document.createElement('script');fff.type = 'text/javascript';fff.async = true;
  fff.src = ('https:' === document.location.protocol ? 'https://' : 'http://') + 'service.finurligefakta.dk/widgets/fff.widget.js';
  var s = document.getElementsByTagName('script')[0];s.parentNode.insertBefore(fff, s);
})();
