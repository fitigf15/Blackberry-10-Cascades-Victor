import bb.cascades 1.2
import bb.data 1.0

Page {
    actions: [
        //! [0]
        ActionItem {
            title: qsTr("Update")
            imageSource: "asset:///images/pin.png"
            ActionBar.placement: ActionBarPlacement.InOverflow
            onTriggered: {
                //_bicing.updateMap()
                _cityBikes.url="http://api.citybik.es/v2/networks/bicing"
            }
        }
        ,
        ActionItem {
            title: qsTr("Go to me")
            imageSource: "asset:///images/me.png"
            ActionBar.placement: ActionBarPlacement.InOverflow
            onTriggered: {
                //_bicing.goToMyLocation()
                _cityBikes.goToDeviceLocation()
            }
        }
    ]
    Container {
        TextField {
            id: textFilter
            hintText: "Filter stations"
            onTextChanging: {
                //_bicing.filterCurrentStationsDataModel(text);
                _cityBikes.applyFilter(text)
            }
        }
        ListView {
            id: listView
            dataModel: _cityBikes.dataModel
            listItemComponents: ListItemComponent {
                type: "item"
                    StationListItem {
                        name: ListItemData.name
                        free_bikes: ListItemData.free_bikes
                        empty_slots: ListItemData.empty_slots
                        timestamp: ListItemData.timestamp
                        status: ListItemData.extra.status.toString()=="OPN"
                    
                    } 
             }
            onTriggered: {
                var selectedItem = dataModel.data(indexPath);
                //_bicing.locationTapped(selectedItem["id"]);
                _cityBikes.inspectStation(selectedItem["id"])
                openPlaceInspector()
            }

        
        }
    }
    
    
    // this function is included locally, but you can also include separately via a header definition

}
