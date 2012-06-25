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

    generator.append($('<label />', {
      'text' : 'Identifier:'
    }).append($('<input />', {
      'name' : 'target',
      'type' : 'text',
      'value' : '#widget'
    })));

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

    //<input type="radio" name="group1" value="Cheese"> Cheese
    
    var red = $('<label />', {
                'text' : 'Red'
              }).append($('<input />', {
                'type' : 'radio',
                'name' : 'color',
                'value' : 'red'
              }));
              
    var green = $('<label />', {
                'text' : 'Green'
              }).append($('<input />', {
                'type' : 'radio',
                'name' : 'color',
                'value' : 'green'
              }));
              
    var blue = $('<label />', {
                'text' : 'Red'
              }).append($('<input />', {
                'type' : 'radio',
                'name' : 'color',
                'value' : 'red'
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
//      alert('generate code');
      return false;
    }));

    // Apped the form.
    target.append(generator);
  });

}(jQuery));

