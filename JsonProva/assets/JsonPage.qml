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

// This details Page for a bucket item that shows the entire task contained in a bucket
// item and adds functionality for editing the item.

Page {
    id: jsonPage
    property variant item
    property variant jsonDataModel
    property alias title: titleBar.title
    
    titleBar: TitleBar {
        id: titleBar
        visibility: ChromeVisibility.Visible
    }
    
    Container {
        layout: DockLayout {
        }
        
        Container {
            rightPadding: leftPadding
            horizontalAlignment: HorizontalAlignment.Left
            
            Label {
                id: jsonText
                multiline: true
                text: jsonPage.item.title
                textStyle.base: SystemDefaults.TextStyles.TitleText
            }
        }
    }
    
    shortcuts: [
        SystemShortcut {
            // The edit short cut shows the edit sheet.
            type: SystemShortcuts.Edit
            onTriggered: {
                editSheet.open();
                editSheet.text = jsonText.text;
            }
        }
    ]
    
    actions: [
        ActionItem {
            title: qsTr("Edit") + Retranslate.onLanguageChanged
            ActionBar.placement: ActionBarPlacement.InOverflow
            
            onTriggered: {
                editSheet.open();
                editSheet.text = jsonText.text;
            }
        }
    ]
    
    attachedObjects: [
        EditSheet {
            id: editSheet
            title: qsTr("Edit") + Retranslate.onLanguageChanged
            hintText: "Update JSON item description"
            
            onSaveJsonItem: {
                // Call the function to update the item data.  
                jsonDataModel.editJsonItem(jsonPage.item, text);
                
                // Update the current item property data used in this Page to do this
                // one has to copy all values to 'tempItem'.
                var tempItem = jsonPage.item
                // Update the item property
                tempItem.title = text
                // Then copy all values back to 'jsonPage.item'
                jsonPage.item = tempItem 
            }
        }
    ]
}
