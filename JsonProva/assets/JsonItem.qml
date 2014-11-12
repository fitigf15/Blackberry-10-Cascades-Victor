/* Copyright (c) 2012, 2013, 2014 BlackBerry Limited.
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

// This the item component for the items in the bucket list. It is a StandardListItem
// with an action set for altering the state of an item and for entering the multi select state.

StandardListItem { 
    id: jsonItem
    title: ListItemData.name
    imageSpaceReserved: false
    description: ListItemData.isFavorite
    
    contextActions: [
        ActionSet {
            title: ListItemData.name
            subtitle: qsTr("Item action") + Retranslate.onLanguageChanged
            
            ActionItem {
                title: qsTr("Favorite/UnFavorite") + Retranslate.onLanguageChanged
                
                onTriggered: {
                    if (enabled) {
                        jsonItem.ListItem.view.dataModel.setIsFavorite(jsonItem.ListItem.indexPath, !ListItemData.isFavorite);
                    }
                }
            }
            DeleteActionItem {
                title: qsTr("Delete") + Retranslate.onLanguageChanged
                
                onTriggered: {
                    jsonItem.ListItem.view.dataModel.deleteJsonItems(jsonItem.ListItem.indexPath);
                }
            }
        }
    ]
}
