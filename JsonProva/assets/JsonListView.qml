import bb.cascades 1.2

ListView {
    property bool hasSelection: false
    id: jsonList
    layoutProperties: StackLayoutProperties {
        spaceQuota: 1
    }
    listItemComponents: [
        ListItemComponent {
            type: "todo"
            
            JsonItem {
                // List item component (see items/TodoItem.qml for definition).
            }
        }
    ]
    
    onTriggered: {
        // When an item is triggered, a navigation takes place to a detailed
        // view of the item where the user can edit the item. The page is created
        // via the ComponentDefinition from the attached objects in the NavigationPane.
        var chosenItem = dataModel.data(indexPath);
        var page = jsonPage.createObject();
        
        // Set the Page properties and push the Page to the NavigationPane.
        page.item = chosenItem;
        page.jsonDataModel = jsonDataModel;
        var option = segmentedTitle.selectedOption;
        page.title = option.text;
        nav.push(page);
    }
    onSelectionChanged: {
        // Call a function to update the number of selected items in the multi-select view.
        updateMultiStatus();
    }
    
    function itemType(data, indexPath) {
        // There is only have one type of item in the list, so "todo" is always returned.
        return "todo";
    }
    function updateMultiStatus() {
        
        // The status text of the multi-select handler is updated to show how
        // many items are currently selected.
        if (selectionList().length > 1) {
            hasSelection = true;
            multiSelectHandler.status = selectionList().length + qsTr(" items selected");
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
                
                title: qsTr("Todo") + Retranslate.onLanguageChanged
                
                // Since it is only possible to change the state from one state to another,
                // ActionItems are disabled if they do not result in a state change.
                // For example, todo -> finished is allowed but todo -> todo is not.
                
                enabled: (jsonDataModel.filter != "todo")
                
                
                onTriggered: {
                    if (enabled) {
                        // Change the status of the selected items to "todo", clear selection before
                        // performing the action, since otherwise the ListItem will not be in the correct
                        // state when it is recycled by the list view (it will blink)
                        var selectionList = jsonList.selectionList();
                        jsonList.clearSelection();
                        jsonDataModel.setStatus(selectionList, "todo");
                    }
                }
            },
            ActionItem {
                
                title: qsTr("Finished") + Retranslate.onLanguageChanged
                
                enabled: (jsonDataModel.filter != "finished")
                
                onTriggered: {
                    if (enabled) {
                        // Change the status of the selected items to "finished". Clear selection before items are manipulated to avoid blink.
                        var selectionList = jsonList.selectionList();
                        jsonList.clearSelection();
                        jsonDataModel.setStatus(selectionList, "finished");
                    }
                }
            },
            ActionItem {
                
                title: qsTr("Chickened out") + Retranslate.onLanguageChanged
                enabled: (jsonDataModel.filter != "chickened")
                
                onTriggered: {
                    if (enabled) {
                        // Change the status of the selected items to "chickened". Clear selection before items are manipulated to avoid blink.
                        var selectionList = jsonList.selectionList();
                        jsonList.clearSelection();
                        jsonDataModel.setStatus(selectionList, "chickened");
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
