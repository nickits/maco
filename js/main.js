//window.addEvent('domready', function() {
window.addEvent('load', function(){
  var list = new TreeAcordion('root',{ 
      //branchClass :'branch', 
      //openerClass: 'handle', 
      //branchContainer : 'li', 
    // acordOpenFunction : function(el,height){/* ... */}, 
    // acordCloseFunction : function(el,height){/* ... */}, 
      multiple: true, 
      debug : false 
      //tl : true 
  });
  //if(sellectionType == "collection"){
    list.toggleBranch($('collections'));
  //}
  //else 
  if(sellectionType == "category"){
    list.toggleBranch($('categories'));
  }

  if($('carousel-3')){
    var moo3DCarousel3 = new Moo3DCarousel('carousel-3',{
	  mouseWheel: false,
	  stopOver: false
    });

    // Event rotateEnd
    moo3DCarousel3.addEvent('rotateEnd', function() {
	    var img = new Element('img', { src: this.getFocused().getProperty('href') });
	    $('carousel-3-focus').empty().adopt( img );
    }.bindWithEvent(moo3DCarousel3) );

    // Click Event on each link
    $$('#carousel-3 a[href$="jpg"]').each( function(elem) {
	  moo3DCarousel3.addElement(elem, {x:75, y:50});
	  elem.addEvent('click', function(ev) {
		  ev.stop();
		  var img = new Element('img', { src: this.getProperty('href') });
		  $('carousel-3-focus').empty().adopt( img );
	  });
    });  
    
    // this overlay hide image in background
    /*
    new Element('div', {
	    styles: {
		    'z-index': 100 + moo3DCarousel3.count(),
		    position: 'absolute',
		    background: 'rgb(245,245,245)',
		    top: 0,
		    left: 0,
		    width: '100%',
		    height: '100%'
	    }
    }).inject( moo3DCarousel3.toElement() );
  */
    $('carousel-3-focus').setStyle('line-height', moo3DCarousel3.getSize().y );
  }
});
