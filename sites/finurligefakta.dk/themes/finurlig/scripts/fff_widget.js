var fffWidgetConfig = [];
fffWidgetConfig.push({
  'widget' : 'interactive',
  'target' : '#fff-widget',
  'style' : {
    'type' : 'hacked'
  },
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
  window.addEventListener('CookieInformationConsentGiven', function (event) {
    if (CookieInformation.getConsentGivenFor('cookie_cat_statistic')) {
      var fff = document.createElement('script');fff.type = 'text/javascript';fff.async = true;
      fff.src = ('https:' === document.location.protocol ? 'https://' : 'http://') + 'service.finurligefakta.dk/widgets/fff.widget.min.js';
      var s = document.getElementsByTagName('script')[0];s.parentNode.insertBefore(fff, s);
    }
  }, false);
})();

