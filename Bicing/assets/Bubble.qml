/* Copyright (c) 2012 Research In Motion Limited.
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

Container {
    property string stationID
    overlapTouchPolicy: OverlapTouchPolicy.Allow
    onStationIDChanged: {   
        if(stationID=="device-location-id"){
            device.visible=true
            nonDevice.visible=false
        }else{
            var propertiesMap = _cityBikes.getStationProperties(stationID)
            device.visible=false
            nonDevice.visible=true
            nameLabel.text=propertiesMap.name
            console.log("JAVASCRIPT ISFAVORITE: " +propertiesMap.isFavorite)
            if(propertiesMap.isFavorite){
                favLabel.text="★"
                favLabel.preferredWidth=40
                favLabel.visible=true
            }else{
                favLabel.text=""
                favLabel.preferredWidth=0
                favLabel.visible=false
            }
            freeBikesLabel.text = "\uD83D\uDEB2 : "+propertiesMap.free_bikes
            emptySlotsLabel.text = "\u24DF : "+propertiesMap.empty_slots
            timestampLabel.text = "\uD83D\uDD50 : "+propertiesMap.localTimestamp
            if(propertiesMap.extra.status=="OPN"){
                statusLabel.visible=false
                freeBikesLabel.visible=true
                emptySlotsLabel.visible=true
                timestampLabel.visible=true
                if(propertiesMap.free_bikes > 5){
                    nameContainer.background=Color.create("#7a00ff00")
                }else if(propertiesMap.free_bikes == 0){
                    nameContainer.background=Color.create("#7aff0000")
                }else{
                    nameContainer.background=Color.create("#7affff00")
                }
            }else{
                freeBikesLabel.visible=false
                emptySlotsLabel.visible=false
                timestampLabel.visible=false
                statusLabel.visible=true
                statusLabel.text="Closed \u2639"
                nameContainer.background=Color.create("#7a000000")
            }
        }
        
    }
    Container {
        id: device
        visible: stationID=="device-location-id"
        Label {
            text: "You"
            textStyle.fontSize: FontSize.XXLarge
            textStyle.color: Color.White
            textStyle.textAlign: TextAlign.Center
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
        }
    }
    Container {
        id: nonDevice
        visible: stationID!="device-location-id"
        leftPadding: 10
        rightPadding: 10
        bottomPadding: 10
        topPadding: 10
        preferredWidth: 720
        overlapTouchPolicy: OverlapTouchPolicy.Allow
        horizontalAlignment: HorizontalAlignment.Center
        verticalAlignment: VerticalAlignment.Center 
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            id: nameContainer
            horizontalAlignment: HorizontalAlignment.Center
            preferredHeight: 75
            preferredWidth: 720
            Label {
                id: favLabel
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                textStyle.color: Color.Yellow
            }
            ScrollView {
                scrollViewProperties.scrollMode: ScrollMode.Horizontal
                scrollViewProperties.overScrollEffectMode: OverScrollEffectMode.OnScroll
                Label {
                    id: nameLabel
                    overlapTouchPolicy: OverlapTouchPolicy.Allow
                    textStyle.color: Color.White
                    textStyle.fontSize: FontSize.Medium
                    textStyle.textAlign: TextAlign.Center
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                }
            }
            
            
        }
        Container {
            preferredWidth: 720
            preferredHeight: 72
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            background: Color.create("#7a00ffff")
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Bottom
            Container {
                preferredWidth: 450
                preferredHeight: 72
                
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                
                Label {
                    preferredWidth: 135
                    id: freeBikesLabel
                    textStyle.textAlign: TextAlign.Center
                    verticalAlignment: VerticalAlignment.Center
                    //preferredWidth: 110
                }
                Label {
                    id: emptySlotsLabel
                    preferredWidth: 135
                    textStyle.textAlign: TextAlign.Center
                    verticalAlignment: VerticalAlignment.Center                  
                    //preferredWidth: 110
                }
                
                Label {
                    id: timestampLabel
                    preferredWidth: 180
                    textStyle.textAlign: TextAlign.Center
                    verticalAlignment: VerticalAlignment.Center
                    //preferredWidth: 160
                }
                Label {
                    id: statusLabel
                    textStyle.textAlign: TextAlign.Center
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                
                }   
            }   
            ImageButton {
                preferredWidth: 90
                defaultImageSource: "asset:///images/ic_nav_to.png"
                horizontalAlignment: HorizontalAlignment.Right
                onClicked:{
                    //_bicing.routeToCurrentStation()
                    _cityBikes.routeTo(stationID)
                }
            }
            ImageButton {
                preferredWidth: 90
                defaultImageSource: "asset:///images/ic_info_black.png"
                horizontalAlignment: HorizontalAlignment.Right 
                onClicked: {
                    //_bicing.inspectCurrentStation()
                    
                    _cityBikes.inspectStation(stationID)
                    openPlaceInspector()
                }
            }          
            
        }   
             
    }
}