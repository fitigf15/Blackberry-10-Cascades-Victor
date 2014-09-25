import bb.cascades 1.2
import QtMobility.sensors 1.2
import bb.cascades.maps 1.2
import QtMobilitySubset.location 1.1

Page {
    actions: [
        //! [0]
        ActionItem {
            title: qsTr("Update")
            imageSource: "asset:///images/pin.png"
            ActionBar.placement: ActionBarPlacement.InOverflow
            onTriggered: {
                _bicing.updateMap()
            }
        }
        ,
        ActionItem {
            title: qsTr("Go to me")
            imageSource: "asset:///images/me.png"
            ActionBar.placement: ActionBarPlacement.InOverflow
            onTriggered: {
                _bicing.goToMyLocation()
            }
        }
    ]
    MapView {
        id: mapview
        altitude: 4000
        objectName: "mapViewObj"
        latitude: 41.3850639
        longitude: 2.1734035
        onMapLongPressed: {
            console.log(qsTr("map long pressed"));
        }
        
        onFollowedIdChanged: {
            console.log(qsTr("followed id changed to %1").arg(idOfFollowed));
        }
        onFocusedIdChanged: {
            console.log(qsTr("focused id changed to %1").arg(idWithFocus));
        }
        onCaptionButtonClicked: {
            //TAP A PIN BUTTOn
            console.log(qsTr("button clicked %1").arg(focusedId));
        }
        onCaptionLabelTapped: {
            //TAP A PIN LABEL
            console.log(qsTr("label clicked %1").arg(focusedId));
        }
        onLocationTapped: {
            _bicing.locationTapped(id);
            //console.log(qsTr("location pressed %1").arg(id));
        }
        onLocationLongPressed: {
            //MAINTAIN A PIN
            console.log(qsTr("location long pressed %1").arg(id));
        }
        captionContent: Bubble {
            objectName: "bubbleObj"
            id: bubble
        }
    
    }
    attachedObjects:  [
        PositionSource {
            id: positionSource
            active: true
            updateInterval: 5000
            onPositionChanged: {
            _bicing.updateDeviceLocation(positionSource.position.coordinate.latitude, positionSource.position.coordinate.longitude)
            }
        },
        Dialog {
            id: nearbyStationsDialog
            objectName: "nearbyStationsDialogObj"
            DialogContent {
            }
            
    }]
//! [4]
}