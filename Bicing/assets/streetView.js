/**
 * 
 */

function initialize(lat, long) {
  var bryantPark = new google.maps.LatLng(lat, long);
  var panoramaOptions = {
    position: bryantPark,
    pov: {
      heading: 165,
      pitch: 0
    },
    zoom: 1
  };
  var myPano = new google.maps.StreetViewPanorama(
      document.getElementById('map-canvas'),
      panoramaOptions);
  myPano.setVisible(true);
}

google.maps.event.addDomListener(window, 'load', initialize);