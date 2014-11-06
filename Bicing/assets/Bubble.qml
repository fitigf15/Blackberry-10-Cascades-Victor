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
    property int free_bikes
    property int empty_slots
    property string name
    property string timestamp
    property string bubbleColor
    property string latitude
    property string longitude
    property bool status
    property bool device
    property bool isFavorite
    overlapTouchPolicy: OverlapTouchPolicy.Allow
    Container {
        leftPadding: 10
        rightPadding: 10
        bottomPadding: 10
        topPadding: 10
        preferredWidth: 720
        overlapTouchPolicy: OverlapTouchPolicy.Allow
        horizontalAlignment: HorizontalAlignment.Center
        verticalAlignment: VerticalAlignment.Center 
        background: parent.background
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            id: nameContainer
            background: {
                if(status){
                    if(free_bikes > 5){
                        return Color.create("#7a00ff00")
                    }
                    if(free_bikes == 0){
                        return Color.create("#7aff0000")
                    }
                    return Color.create("#7affff00")
                }
                return Color.create("#7a000000")
            }
            horizontalAlignment: HorizontalAlignment.Center
            preferredHeight: 65
            preferredWidth: parent.preferredWidth
            visible: !device
            Label {
                preferredWidth: 40
                text: "\u2605"
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                textStyle.color: Color.Yellow
                visible: isFavorite
            }
            ScrollView {
                scrollViewProperties.scrollMode: ScrollMode.Horizontal
                scrollViewProperties.overScrollEffectMode: OverScrollEffectMode.OnScroll
                Label {
                    overlapTouchPolicy: OverlapTouchPolicy.Allow
                    text: name
                    textStyle.color: Color.White
                    textStyle.fontSize: FontSize.Medium
                    textStyle.textAlign: TextAlign.Center
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                }
            }
            
            
        }
        Container {
            preferredHeight: 72
            preferredWidth: parent.preferredWidth
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            background: Color.create("#7a00ffff")
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Bottom
            Container {
                preferredHeight: 72
                
                preferredWidth: parent.preferredWidth/1.2
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                
                Label {
                    visible: status && !device
                    text: "\uD83D\uDEB2 : "+free_bikes.toString()
                    textStyle.textAlign: TextAlign.Center
                    verticalAlignment: VerticalAlignment.Center
                    //preferredWidth: 110
                }
                Label {
                    visible: status && !device
                    text: "\u24DF : "+empty_slots.toString() 
                    textStyle.textAlign: TextAlign.Center
                    verticalAlignment: VerticalAlignment.Center                  
                    //preferredWidth: 110
                }
                
                Label {
                    visible: status && !device
                    text: "\uD83D\uDD50 : "+timestamp
                    textStyle.textAlign: TextAlign.Center
                    verticalAlignment: VerticalAlignment.Center
                    //preferredWidth: 160
                }
                Label {
                    visible: !status && !device
                    text: "Closed \u2639"
                    textStyle.textAlign: TextAlign.Center
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                
                }
                
                Label {
                    text: "You"
                    visible: !status && device
                    textStyle.fontSize: FontSize.XXLarge
                    textStyle.color: Color.White
                    textStyle.textAlign: TextAlign.Center
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                }
                
                
            }
            Container {
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                ImageButton {
                    defaultImageSource: "asset:///images/ic_nav_to.png"
                    horizontalAlignment: HorizontalAlignment.Right
                    onClicked:{
                        _bicing.routeToCurrentStation()
                    }
                }
                ImageButton {
                    defaultImageSource: "asset:///images/ic_info_black.png"
                    horizontalAlignment: HorizontalAlignment.Right 
                    onClicked: {
                        _bicing.inspectCurrentStation()
                        openPlaceInspector()
                    }
                }
                ImageButton {
                    defaultImageSource: "asset:///images/ic_share_black.png"
                    horizontalAlignment: HorizontalAlignment.Right
                    onClicked: {
                        share(name,status,free_bikes.toString(),empty_slots.toString(),timestamp.toString())
                        
                    }
                }
            }
            
            
        }   
             
    }
    
    onBubbleColorChanged: {
        nameContainer.background = Color.create(bubbleColor)
    }
}