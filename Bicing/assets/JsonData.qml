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
    Container {
        TextField {
            id: textFilter
            hintText: "Filter stations"
            onTextChanging: {
                _bicing.filterCurrentStationsDataModel(text);
            }
        }
        ListView {
            id: listView
            dataModel: _bicing.currentStationsDataModel
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
                _bicing.locationTapped(selectedItem["id"]);
                _bicing.inspectCurrentStation()
                openPlaceInspector()
            }

        
        }
    }
    
    
    // this function is included locally, but you can also include separately via a header definition

}
