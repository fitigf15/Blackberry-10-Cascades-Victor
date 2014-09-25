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
import QtMobility.sensors 1.2
import bb.cascades.maps 1.2
import QtMobilitySubset.location 1.1

TabbedPane {
    objectName: "tabbedPaneObj"
    id: root
    showTabsOnActionBar: true
    activeTab: map
    Tab { //First tab
        id: map
        // Localized text with the dynamic translation and locale updates support
        title: qsTr("Map") + Retranslate.onLocaleOrLanguageChanged
        Map {
            id: mapPage   
        }
    } //End of first tab
    Tab { //Second tab
        id: stations
        title: qsTr("Stations") + Retranslate.onLocaleOrLanguageChanged
        JsonData {
            id: stationsPage            
        }
    } //End of second tab
    Tab {
        
        title: qsTr("Inspector") + Retranslate.onLocaleOrLanguageChanged
        id: placeInspector
        Page {
            
            id: placeInspectorPage
            PlaceInspector {
                
            }
        }
    }
    function loadJSON(path, success, error)
    {
        var xhr = new XMLHttpRequest();
        xhr.onreadystatechange = function()
        {
            if (xhr.readyState === 4) {
                if (xhr.status === 200) {
                    if (success)
                        success(JSON.parse(xhr.responseText));
                } else {
                    if (error)
                        error(xhr);
                }
            }
        };
        xhr.open("GET", path, true);
        xhr.send();
    }
    function updateNetwork(nw){
        loadJSON("http://api.citybik.es/v2/networks/"+nw, function(data){
                var item;
                _bicing.currentNetwork=data.network;
                //estacionsPage.stationsModel.clear()
                //estacionsPage.stationsModel.insertList(_bicing.current.stations)
                _bicing.updateMap()
                /*for(item in _bicing.current.stations){
                 mapPage.pins.addPin(_bicing.current.stations[0].latitude, _bicing.current.stations[0].longitude)
                 }*/
                console.log("UPDATED!!")
        }, function(data){console.log(data)});
    }
    function updateNetworks(){
        loadJSON("http://api.citybik.es/v2/networks", function(data){
                var item;
                _bicing.nets=data.networks;
        }, function(data){console.log(data)});
    }
}

