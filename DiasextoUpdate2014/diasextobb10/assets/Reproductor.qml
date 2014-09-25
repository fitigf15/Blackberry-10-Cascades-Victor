import bb.cascades 1.2
import bb.multimedia 1.0

Container {
    // ...
    function setURL(u){
        player.sourceUrlChanged(u)
    }
    attachedObjects: [
        MediaPlayer {
            id: player
            // Set these properties for video
            videoOutput: VideoOutput.PrimaryDisplay
            windowId: fwcVideoSurface.windowId
            
            onMediaStateChanged: {
                switch (player.mediaState) {
                    case MediaState.Unprepared:
                        break;
                    case MediaState.Prepared:
                        break;
                    // ...
                }
            }
            onDurationChanged: {
                sl.toValue=duration
            
            }
            onPositionChanged: {
                sl.value=position
            
            }
        
        
        }
    ]
    
    
    ForeignWindowControl {
        id: fwcVideoSurface
        windowId: "myVideoSurface"
        visible: boundToWindow
        
        updatedProperties: WindowProperty.Size |
        WindowProperty.Position |
        WindowProperty.Visible
    }
    
    Slider {
        id: sl
        onValueChanged: {
            if(Math.abs(value-player.position)>1000){
                player.seekTime(value)
            }
        }
    
    }
    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }
        
        Label {
            
            text: Math.floor(((((player.position / 1000) % 31536000) % 86400) % 3600) / 60) + ":" + Math.floor(((((player.position / 1000) % 31536000) % 86400) % 3600) % 60)
            layoutProperties: StackLayoutProperties {
            
            }
            horizontalAlignment: HorizontalAlignment.Left
            textStyle.textAlign: TextAlign.Left
            preferredWidth: 360
        }
        Label {
            text: Math.floor(((((player.duration / 1000) % 31536000) % 86400) % 3600) / 60) + ":" + Math.floor(((((player.duration / 1000) % 31536000) % 86400) % 3600) % 60)
            horizontalAlignment: HorizontalAlignment.Right
            preferredWidth: 360
            textStyle.textAlign: TextAlign.Right
        
        }
    }
    // ...
    
    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }
        Button {
            id: btnPlay
            text: "Play"
            onClicked: {
                if (player.play() != MediaError.None) {
                    // Your error handling code here.
                } else {
                
                }
            }
        }
        Button {
            id: btnPause
            text: "Pause"
            onClicked: {
                if (player.pause() != MediaError.None) {
                
                } else {
                
                }
            }
        
        }
        Button {
            id: btnStop
            text: "Stop"
            onClicked: {
                player.stop();
            }
        }
        
        Button {
            id: btnReset
            text: "Reset"
            onClicked: {
                player.reset();
            }
        }
    } 

}
