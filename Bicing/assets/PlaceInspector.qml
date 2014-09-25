import bb.cascades 1.2
Container {
 
     property int free_bikes
     property int empty_slots
     property string name
     property string timestamp
     property string bubbleColor
     property bool status
     property bool device
     property bool isFavorite
     objectName: "inspectorObj"
     ImageView {
         image: _bicing.staticMapImage
         scalingMethod: ScalingMethod.Fill
     }
     Divider {
         
     }
     Container {
         layout: StackLayout {
             orientation: LayoutOrientation.LeftToRight
         }
         Label {
             multiline: true
             //name
         }
         Container {
             background: {
                 if(status){
                     if(free_bikes > 5){
                         return Color.create("#7a00ff00")
                     }
                     if(free_bikes == 0){
                         return Color.create("#7aff0000")
                     }
                     return Color.create("#7affff00")
                 }
                 return Color.create("#7a000000")
             }
         }
         Label {
             //distance
         }
    
     }
     Divider {
         
     }
     Container {
         ToggleButton {
             onCheckedChanged: {
                 if(checked){
                     streetView.visible=true
                 }else{
                     streetView.visible=false
                 }
             }
         }
         WebView {
             html: "<html>
                         <head>
                             <meta charset='utf-8'>
                             <style>
                                 html,body,#map-canvas{
                                     height:100%;
                                     margin:0px;
                                     padding:0px;
                                 }
                             </style>
                             <script src=\"https://maps.googleapis.com/maps/api/js?v=3.exp\"></script>
                             <scipt type=\"text/javascript\">
                                 navigator.cascades.onLatLonChanged(lat,lon){
                                     var place = new google.maps.LatLng(lat,lon);
                                     var panoramaOptions = {
                                         position: place,
                                         pov: {
                                             heading: 165,
                                             pitch: 0
                                         },
                                         zoom: 1
                                     };
                                     var myPano = new google.maps.StreetViewPanorama(document.getElementById('map-canvas'),panoramaOptions);
                                     myPano.setVisible(true)
                                 }
                                 google.maps.event.addDomListener(window,'load',onLatLonChanged)
                            </script>
                        </head>
                        <body>
                            <div id=\"map-canvas\"></div>
                        </body>
                         
                    </html>"
            onMessageReceived: {
                
            }
             id: streetView
             visible: false
             
         }
     }
     Divider {
         
     }
     Container {
         layout: StackLayout {
             orientation: LayoutOrientation.LeftToRight
         }
         Label {
             //free
             text: "\uD83D\uDEB2: " + free_bikes.toString()
         }
         Label {
             //empty
             text: "\u24DF: "  + empty_slots.toString()
         }
         Label {
             //updated
             text: "\uD83D\uDD50: "+ timestamp
         }
     }
     Divider {
         
     }
     Container {
         Label {
             text: "Nearby stations"
         }
         ListView {
             id: listView
             dataModel: _bicing.currentNearbyStationsDataModel
             listItemComponents: ListItemComponent {
                 type: "item"
                 StationListItem {
                     id: li
                     name: ListItemData.name
                     free_bikes: ListItemData.free_bikes
                     empty_slots: ListItemData.empty_slots
                     timestamp: ListItemData.timestamp
                     status: ListItemData.extra.status.toString()=="OPN" 
                 }
             }
             onTriggered: {
                 var selectedItem = dataModel.data(indexPath);
                 _bicing.locationTapped(selectedItem["id"]);
                 _bicing.inspectCurrentStation()
             }
         
         }
     }
     
}
