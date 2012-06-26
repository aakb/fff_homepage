(function($) {
  "use strict";

  $(document).ready(function() {
    // Find place to append the generator.
    var target = $('a[name=node-525]').parent();

    // Form element
    var generator = $('<form />', {
     'id' : 'fff-widget-generator',
     'name' : 'fff-widget-generator',
     'method' : 'post',
     'action' : '#'
    });

    // Add taget.
    generator.append($('<label />', {
      'text' : 'Identifier:'
    }).append($('<input />', {
      'name' : 'target',
      'type' : 'text',
      'value' : '#widget'
    })));

    // Add type optsions.
    generator.append($('<label />', {
      'text' : 'Type:'
    }).append($('<select />', {
                'name' : 'type'
              }).append($('<option />', {
                'value' : 'interactive',
                'text' : 'Interactive'
              })).append($('<option />', {
                'value' : 'slidein',
                'text' : 'Slide in'
              }))));

    // Add style options.
    generator.append($('<label />', {
      'text' : 'Style:'
    }).append($('<select />', {
                'name' : 'style'
              }).append($('<option />', {
                'value' : 'minimal',
                'text' : 'Minimal'
              })).append($('<option />', {
                'value' : 'normal',
                'text' : 'Normal'
              })).append($('<option />', {
                'value' : 'full',
                'selected' : 'selected',
                'text' : 'Full'
              }))));

    // Add color options.
    var red = $('<label />', {
                'text' : 'Red'
              }).append($('<input />', {
                'type' : 'radio',
                'name' : 'color',
                'value' : 'red',
                'checked' :'checked'
              }));
              
    var green = $('<label />', {
                'text' : 'Green'
              }).append($('<input />', {
                'type' : 'radio',
                'name' : 'color',
                'value' : 'green'
              }));
              
    var blue = $('<label />', {
                'text' : 'Blue'
              }).append($('<input />', {
                'type' : 'radio',
                'name' : 'color',
                'value' : 'blue'
              }));
              
    var orange = $('<label />', {
                'text' : 'Orange'
              }).append($('<input />', {
                'type' : 'radio',
                'name' : 'color',
                'value' : 'orange'
              }));
    
    var turquioise = $('<label />', {
                'text' : 'Turquioise'
              }).append($('<input />', {
                'type' : 'radio',
                'name' : 'color',
                'value' : 'turquioise'
              }));
    
    generator.append($('<fieldset />').append($('<legend />', {
                       'text' : 'Colors'
                     })
                     .append(red)
                     .append(green)
                     .append(blue)
                     .append(orange)
                     .append(turquioise)));

    // Add submit handler.
    generator.append($('<input />', {
      'type' : 'button',
      'value' : 'Generate widget code'
    }).click(function(e) {
      e.stopPropagation();
      e.preventDefault();
      fff_code_generator();
      return false;
    }));

    // Apped the form.
    target.append(generator);
  });

  function fff_code_generator() {
    var target = $('#fff-widget-generator input[name="target"]').val();
    var type = $('#fff-widget-generator select[name="type"]').val();
    var style = $('#fff-widget-generator select[name="style"]').val();
    var color = $('#fff-widget-generator input[@name="color"]:checked').val();
    
    // Generate widget configuration.
    var config = "var fffWidgetConfig = [];\n";
    config += "fffWidgetConfig.push({\n";
    config += "  'widget' : '"+type+"',\n";
    config += "  'target' : '"+target+"',\n";
    config += "  'style' : {\n";
    config += "    'type' : '"+style+"',\n";
    config += "    'color' : '"+color+"'\n";
    config += "  },\n";
    config += "  'tracking' : true,\n";
    config += "  'button' : {\n";
    config += "     'reload' : true\n";
    config += "  },\n";
    config += "  'event' : {\n";
    config += "    'loadComplet' : null\n";
    config += "  }\n";
    config += "});\n\n";
    
    var load = "(function() {\n";
    load += "  var fff = document.createElement('script'); fff.type = 'text/javascript'; fff.async = true;\n";
    load += "  fff.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + 'service.finurligefakta.dk/widgets/fff.widget.js';\n";
    load += "  var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(fff, s);\n";
    load += "})();"
    
    console.log(config + load);
    return config;
  }

}(jQuery));

