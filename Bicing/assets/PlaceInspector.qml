import bb.cascades 1.2
Sheet {
    id: rootPage
    property int free_bikes
    property int empty_slots
    property string lat
    property string lon
    property string name
    property string timestamp
    property bool isFavorite
    property bool device
    property bool status
    objectName: "placeInspectorObj"
    peekEnabled: false
    Page {
        
        titleBar: TitleBar {
            title: name
            dismissAction: ActionItem {
                title: "close"
                onTriggered: {
                    placeInspector.close()
                }
            }
        
        }
        Container {
            Container {
                SegmentedControl {
                    options: [Option{
                            text: "Information"
                    },Option {
                        text: "Street View"
                    }
                ]
                onSelectedIndexChanged: {
                    if(selectedIndex==0){
                        streetView.visible=false
                        information.visible=true
                    }
                    else{
                        streetView.visible=true
                        information.visible=false
                    }
                }
                }
                StreetView {
                    id: streetView
                    visible: false
                    latitude: lat
                    longitude: lon
                }
                Container {
                    id: information
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
                            id: freeBikesLabel
                            text: "\uD83D\uDEB2: " + free_bikes.toString()
                        
                        }
                        Label {
                            id: emptySlotsLabel
                            text: "\u24DF: "  + empty_slots.toString()
                        }
                        Label {
                            id: timestampLabel
                            text: if(timestamp)"\uD83D\uDD50: "+ timestamp
                        }
                    }
                    Divider {
                    
                    }
                    Container {
                        layout: StackLayout {
                            orientation: LayoutOrientation.LeftToRight
                        }
                        TextField {
                            visible: false
                            id: textFilter
                            hintText: "Filter stations"
                            onTextChanging: {
                                _bicing.filterCurrentNearbyStationsDataModel(text);
                            }
                        }
                        Button {
                            text: "\uD83D\uDD0E" 
                            preferredWidth: 90
                            onClicked: {
                                textFilter.visible=(!textFilter.visible)
                                nearbyLabel.visible=(!nearbyLabel.visible)
                                if(textFilter.visible){
                                    text = "X"
                                }else{
                                    text = "\uD83D\uDD0E" 
                                }
                            }
                        }
                        Label {
                            id: nearbyLabel
                            text: "Nearby stations"
                            verticalAlignment: VerticalAlignment.Center
                        
                        }
                    
                    
                    }
                    Divider {
                    
                    }
                    ListView {
                        id: listView
                        dataModel: _bicing.currentNearbyStationsDataModel
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
                            free_bikes=selectedItem["free_bikes"]
                            empty_slots=selectedItem["empty_slots"]
                            lat=selectedItem["latitude"]
                            lon=selectedItem["longitude"]
                            name=selectedItem["name"]
                            timestampselectedItem["timestamp"]
                        }
                    
                    }
                }
            
            }
        
        }
    }





}
