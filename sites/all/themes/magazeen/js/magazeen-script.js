// $Id $

//js support for rounded corners across all browsers
Drupal.behaviors.magazeenRoundedCorners = function (context) {

//round top corners

if ($.browser.msie) {
  $(".magazeen-rounded-block .inner").corner({
    tl: { radius: 8 },
    tr: { radius: 8 },
    bl: { radius: 8 },
    br: { radius: 8 },
    antiAlias: true,
    validTags: ["div"] 
  });
  
 $(".magazeen-rounded-block .content").corner({
    tl: { radius: 8 },
    tr: { radius: 8 },
    bl: { radius: 8 },
    br: { radius: 8 },
    antiAlias: true,
    validTags: ["div"] 
  });
  
  $(".magazeen-rounded-list ul.menu li").corner({
    tl: { radius: 10 },
    tr: { radius: 10 },
    bl: { radius: 10 },
    br: { radius: 10 },
    antiAlias: true,
    validTags: ["div"] 
  });
  
    $(".magazeen-rounded-list .item-list ul li").corner({
    tl: { radius: 10 },
    tr: { radius: 10 },
    bl: { radius: 10 },
    br: { radius: 10 },
    antiAlias: true,
    validTags: ["div"] 
  });
  
  }
  
  //fixes for IE 6 & 7 
  if ($.browser.msie && $.browser.version.substr(0,1)<8) {
    $('#main-content-inner .rounded-all #cctopcontainer').css('marginRight', 'auto');
    $('#main-content-inner .rounded-all #cctopcontainer').css('left', '21');
    $('#main-content-inner .rounded-all #ccbottomcontainer').css('marginRight', 'auto');
    $('#main-content-inner .rounded-all #ccbottomcontainer').css('left', '21');
  }			  
}; //end js support for rounded corners

