var beachMarker = [];
jQuery(document).ready(function () {
    var myOptions, map, infowindow, count, i, myLatLng, content;
    myOptions = {
        zoom: 14,
        center: new google.maps.LatLng(Drupal.settings.event_map.markers[1], Drupal.settings.event_map.markers[2]),
        mapTypeId: google.maps.MapTypeId.ROADMAP
    };
    map = new google.maps.Map(document.getElementById("map_canvas"),
                                  myOptions);

    infowindow = [];
    infowindow = new google.maps.InfoWindow({
        content: 'this'
    });
    count = 0;
    for (i in Drupal.settings.event_map.markers) {
        myLatLng = new google.maps.LatLng(Drupal.settings.event_map.markers[1], Drupal.settings.event_map.markers[2]);
        content = Drupal.settings.event_map.markers[0];

        beachMarker[count] = new google.maps.Marker({
            position: myLatLng,
            map: map,
            html: content
        });
        google.maps.event.addListener(beachMarker[count], 'click', function () {
            infowindow.setContent(this.html);
            infowindow.open(map, this);
        });
        count = count + 1;
    }
});
