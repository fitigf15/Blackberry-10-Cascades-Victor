import bb.cascades 1.2
import bb.data 1.0
import bb.cascades.maps 1.2

Page {
    property alias dataSource
    /*
    Container {
        //Todo: fill me with QML
        Container {
            preferredHeight: 500
            preferredWidth: 768
            MapView {
                id: mapView
                latitude: 41.37516
                longitude: 2.14922
                altitude: 1000
                
                onCreationCompleted: {
                    setRenderEngine("RenderEngine3D")
                }
            
            }
        }
    
    }*/
    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.TopToBottom
        }
        horizontalAlignment: HorizontalAlignment.Center
        verticalAlignment: VerticalAlignment.Center     
        MapView {
            id: mapViewId
            latitude: 43.4706
            longitude: -80.5361
            mapData: MapData {
                dataProviders: [
                    DataProvider {
                        id: dataProvider
                        providerId: "dataProvider"
                        visible: true
                    }
                ]
            }
        }
    }
    attachedObjects: [
        GeographicsProvisioningBridge {
            id: exampleBridge
            source: "asset:///placemark.kml"
            destinationProvider: dataProvider
        }
    ]
    onCreationCompleted: {
        exampleBridge.load();
    }

}
