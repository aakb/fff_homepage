(function($) {
  "use strict";

  $(document).ready(function() {
    // Outer wrapper.
    var generatorWrapper = $('<div />', { 'class' : 'fff-widget-generator-wrapper' }).hide();

    // Form element.
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
                'value' : 'none',
                'text' : 'None'
              })).append($('<option />', {
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
                'value' : 'default',
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
                     }))
                     .append(red)
                     .append(green)
                     .append(blue)
                     .append(orange)
                     .append(turquioise));

    generator.append($('<label />', {
      'text' : 'Tillad tracking af forbrug (Google Analytices)'
    }).append($('<input />', {
      'type' : 'checkbox',
      'name' : 'tracking',
      'checked' : 'checked',
      'value' : 'tracking',
      'class' : 'tracking'
    })));

    // Add submit handler.
    generator.append($('<input />', {
      'class' : 'fff-widget-generator-btn',
      'type' : 'button',
      'value' : 'Generer kode'
    }));

    // Insert generator.
    var target = $('a[name=node-525]').parent();
    target.append(generatorWrapper.append(generator));
    generatorWrapper.fadeIn();

    // Code wrapper
    var codeWrapper = $('<div />', {'id' : 'fff-widget-code-wrapper'}).hide();
    var code = $('<pre />', {'id' : 'fff-widget-code'});
    codeWrapper.append(code);
    codeWrapper.append($('<input />', {
      'type' : 'button',
      'value' : 'Prøv med en anden konfiguration'
    }).click(function (e) {
      e.stopPropagation();
      e.preventDefault();

      codeWrapper.fadeOut(function() {
        // Insert generator.
        generatorWrapper.fadeIn();
      });
    }));

    target.append(codeWrapper);

    $('.fff-widget-generator-btn').click(function(e) {
      e.stopPropagation();
      e.preventDefault();

      // Generate code and insert into
      code.text(fff_code_generator());

      // If code is click select all.
      codeWrapper.click(function() {
        var doc = document;
        var text = doc.getElementById('fff-widget-code');
        var range;

        if (doc.body.createTextRange) { // ms
            range = doc.body.createTextRange();
            range.moveToElementText(text);
            range.select();
        } else if (window.getSelection) { // moz, opera, webkit
            var selection = window.getSelection();
            range = doc.createRange();
            range.selectNodeContents(text);
            selection.removeAllRanges();
            selection.addRange(range);
        }
      });

      generatorWrapper.fadeOut(function() {
        // Insert code.
        codeWrapper.fadeIn();
      });

      return false;
    });


  });

  function fff_code_generator() {
    var target = $('#fff-widget-generator input[name="target"]').val();
    var type = $('#fff-widget-generator select[name="type"]').val();
    var style = $('#fff-widget-generator select[name="style"]').val();
    var color = $('#fff-widget-generator input[@name="color"]:checked').val();

    // Generate widget configuration.
    var config = "  var fffWidgetConfig = [];\n";
    config += "  fffWidgetConfig.push({\n";
    config += "    'widget' : '"+type+"',\n";
    config += "    'target' : '"+target+"',\n";
    config += "    'style' : {\n";
    config += "      'type' : '"+style+"',\n";
    config += "      'color' : '"+color+"'\n";
    config += "    },\n";
    config += "    'tracking' : true,\n";
    config += "    'button' : { 'reload' : true },\n";
    config += "    'event' : { 'loadComplet' : null }\n";
    config += "  });\n\n";

    // Generate widget load code.
    var load = "  (function() {\n";
    load += "    var fff = document.createElement('script'); fff.type = 'text/javascript'; fff.async = true;\n";
    load += "    fff.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + 'service.finurligefakta.dk/widgets/fff.widget.min.js';  \n";
    load += "    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(fff, s);\n";
    load += "  })();\n";

    return "<script type=\"text/javascript\">\n" + config + load + "</script>\n";
  }

}(jQuery));

