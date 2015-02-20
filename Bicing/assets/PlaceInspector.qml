import bb.cascades 1.3
Sheet {
    id: rootPage
    property string placeID
    objectName: "placeInspectorObj"
    peekEnabled: false
    onClosed: {
        _cityBikes.selectOriginalList()
    }
    onPlaceIDChanged: {
        console.log("PLACE ID CHANGED")
        var placeMap = _cityBikes.getStationProperties(placeID)
        _cityBikes.inspectStation(placeMap["id"])
        freeBikesLabel.text="\uD83D\uDEB2: " + placeMap["free_bikes"]
        emptySlotsLabel.text="\u24DF: "  + placeMap["empty_slots"]
        streetView.latitude=placeMap["latitude"]
        streetView.longitude=placeMap["longitude"]
        titleBar.title=placeMap["name"]
        timestampLabel.text="\uD83D\uDD50: "+ placeMap["localTimestamp"]
        
    }
    Page {
        
        titleBar: TitleBar {
            id: titleBar
            dismissAction: ActionItem {
                title: "close"
                onTriggered: {
                    placeInspector.close()
                    _cityBikes.resetList()
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
                }
                Container {
                    id: information
                    ImageView {
                        id: staticMapImageView
                        scalingMethod: ScalingMethod.Fill
                        image: _cityBikes.staticMapImage
                    }
                    Divider {
                    
                    }  
                    Container {
                        layout: StackLayout {
                            orientation: LayoutOrientation.LeftToRight
                        }
                        Label {
                            id: freeBikesLabel
                        
                        }
                        Label {
                            id: emptySlotsLabel
                            
                        }
                        Label {
                            id: timestampLabel
                            
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
                                //_bicing.filterCurrentNearbyStationsDataModel(text);
                                _cityBikes.applyFilter(text)
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
                        //dataModel: _bicing.currentNearbyStationsDataModel
                        dataModel: _cityBikes.dataModel
                        listItemComponents: ListItemComponent {
                            type: "item"
                            StationListItem {
                                name: ListItemData.name
                                free_bikes: ListItemData.free_bikes
                                empty_slots: ListItemData.empty_slots
                                timestamp: ListItemData.localTimestamp
                                status: ListItemData.extra.status.toString()=="OPN"
                            
                            } 
                        }
                        onTriggered: {
                            var selectedItem = dataModel.data(indexPath);
                            //_bicing.locationTapped(selectedItem["id"]);
                            //_bicing.inspectCurrentStation()
                            _cityBikes.inspectStation(selectedItem["id"])
                            freeBikesLabel.text="\uD83D\uDEB2: " + selectedItem["free_bikes"]
                            emptySlotsLabel.text="\u24DF: "  + selectedItem["empty_slots"]
                            streetView.latitude=selectedItem["latitude"]
                            streetView.longitude=selectedItem["longitude"]
                            titleBar.title=selectedItem["name"]
                            timestampLabel.text="\uD83D\uDD50: "+ selectedItem["localTimestamp"]
                            staticMapImageView.image=_cityBikes.staticMapImage
                        }
                    
                    }
                }
            
            }
        
        }
    }





}
