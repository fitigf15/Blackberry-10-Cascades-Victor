/*
 * Copyright (c) 2011-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import bb.cascades 1.2
import com.jsondatamodel 1.0
NavigationPane {
    id: nav
    Page {
        
        // Attached objects of the Bucket List Page
        attachedObjects: [
            EditSheet {
                // A sheet is used to add new items to the list, which is the same sheet used to edit items
                id: addNew
                
                onSaveJsonItem: {
                    jsonDataModel.addJsonItem(text);
                    jsonList.scrollToPosition(ScrollPosition.Beginning, ScrollAnimation.Default);
                }
            },
            ComponentDefinition {
                // A Component definition of the Page used to display more details on the Bucket item.
                id: bucketPage
                source: "JsonPage.qml"
            }
        ]
        
        actions: [
            MultiSelectActionItem {
                onTriggered: {
                    jsonList.multiSelectHandler.active = true;
                }
            }
        ]
        
        titleBar: TitleBar {
            id: segmentedTitle
            kind: TitleBarKind.Segmented
            scrollBehavior: TitleBarScrollBehavior.Sticky
            
            // The segmented control decides which filter should be set on the
            // dataModel used by the photo bucket list.
            options: [
                Option {
                    // We dont want to allow the user to navigate while multiselecting so we disable if the lists multiSelectHandler is active.
                    enabled: !jsonList.multiSelectHandler.active
                    text: qsTr("all") + Retranslate.onLanguageChanged
                    value: ("all")
                },
                Option {
                    enabled: !jsonList.multiSelectHandler.active
                    text: qsTr("favorites") + Retranslate.onLanguageChanged
                    value: ("favorites")
                }
            ]
            
            onSelectedValueChanged: {
                // When a new Option is selected the dataModel of the ListView, the jsonDataModels
                // filter is set and the list is repopulated.
                jsonList.favSelected=selectedValue.toString()=="favorites"
                console.log(selectedValue.toString())
            }
        }
        Container {
            Container {
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                TextField {
                    id: textFilter
                    hintText: "Filter stations"
                    onTextChanging: {
                        jsonDataModel.applyFilter(textFilter.text)
                    }
                }
            }
            
            ListView {
                property bool hasSelection: false
                property bool favSelected: false
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                id: jsonList
                /*listItemProvider: JsonItemProvider{
                    
                }*/
                listItemComponents: [
                    ListItemComponent {
                        type: "favorite"
                        
                        JsonItem {
                        }
                    },
                    ListItemComponent {
                        type: "nonFavorite"
                        JsonItem {
                            visible: !ListItem.view.favSelected
                        }
                    }
                ]
                dataModel: JsonDataModel{
                    jsonDataPath: "network/stations"
                    jsonAssetPath: "app/native/assets/bicing.json"
                    id: jsonDataModel
                    
                    
                }
                onTriggered: {
                    // When an item is triggered, a navigation takes place to a detailed
                    // view of the item where the user can edit the item. The page is created
                    // via the ComponentDefinition from the attached objects in the NavigationPane.
                    var chosenItem = dataModel.data(indexPath);
                    console.log(chosenItem.isFavorite);
                    console.log(chosenItem.type)
                    /*var page = bucketPage.createObject();
                    
                    // Set the Page properties and push the Page to the NavigationPane.
                    page.item = chosenItem;
                    page.jsonDataModel = jsonDataModel;
                    var option = segmentedTitle.selectedOption;
                    page.title = option.text;
                    nav.push(page);*/
                }
                
                onSelectionChanged: {
                    // Call a function to update the number of selected items in the multi-select view.
                    updateMultiStatus();
                }
                
                function itemType(data, indexPath) {
                    // There is only have one type of item in the list, so "todo" is always returned.
                    if(data["isFavorite"]==true){
                        return "favorite"
                    }
                    return "nonFavorite";
                }
                function updateMultiStatus() {
                    
                    // The status text of the multi-select handler is updated to show how
                    // many items are currently selected.
                    if (selectionList().length > 1) {
                        hasSelection = true;
                        multiSelectHandler.status = selectionList().length + qsTr(" items selected");
                        for(var item in selectionList()){
                            //console.log(dataModel.data(selectionList()[item])["name"].toString())
                            if(dataModel.data(selectionList()[item])["isFavorite"]==true){
                                favEnabled=false;
                                break
                            
                            }
                        }
                    } else if (selectionList().length == 1) {
                        hasSelection = true
                        multiSelectHandler.status = qsTr("1 item selected");
                    } else {
                        hasSelection = false
                        multiSelectHandler.status = qsTr("None selected");
                    }
                }
                // This multi-select action will be placed inside the ActionSets of each
                // list item that doesn't have a MultiSelectActionItem of its own. The list item
                // has to have an actionset but it can be empty.
                multiSelectAction: MultiSelectActionItem {
                }
                
                // The multi-select handler of the ListView, which will add an additional multi-select item to the list-items
                // context menu (accessed by long-pressing an item). In the multi-select session, it is possible to select
                // several items in the list and perform a collective action on them (like e.g. deleting many items at once).
                multiSelectHandler {
                    status: qsTr("None selected") + Retranslate.onLanguageChanged
                    
                    // The actions that can be performed in a multi-select sessions are set up in the actions list.
                    actions: [
                        ActionItem {
                            
                            title: qsTr("Unfavorite") + Retranslate.onLanguageChanged
                            
                            
                            onTriggered: {
                                if (enabled) {
                                    // Change the status of the selected items to "finished". Clear selection before items are manipulated to avoid blink.
                                    var selectionList = jsonList.selectionList();
                                    jsonList.clearSelection();
                                    jsonDataModel.setIsFavorite(selectionList, false)
                                }
                            }
                        },
                        ActionItem {
                            
                            title: qsTr("Favorite") + Retranslate.onLanguageChanged
                            
                            onTriggered: {
                                if (enabled) {
                                    // Change the status of the selected items to "chickened". Clear selection before items are manipulated to avoid blink.
                                    var selectionList = jsonList.selectionList();
                                    jsonList.clearSelection();
                                    jsonDataModel.setIsFavorite(selectionList, true);
                                }
                            }
                        },
                        // Since the delete action has a reserved space at the bottom of the list in the
                        // context menu it needs to be defined as a special DeleteActionItem to be shown in the
                        // correct place.
                        DeleteActionItem {
                            id: deleteAction
                            title: qsTr("Delete") + Retranslate.onLanguageChanged
                            
                            onTriggered: {
                                // Delete the selected items. Clear selection before items are manipulated to avoid blink.
                                var selectionList = jsonList.selectionList();
                                jsonList.clearSelection();
                                jsonDataModel.deleteJsonItems(selectionList);
                            }
                        }
                    ]
                }
            }
        }
    
    }

}
