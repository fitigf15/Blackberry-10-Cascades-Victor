import bb.cascades 1.2
Page {
    
    // Title Bar with accept and dimiss options
    titleBar: TitleBar {
        title: "Configuración"
        acceptAction: ActionItem {
            title: "Aceptar"
            onTriggered: {
                nav.image.visible=togImagen.checked
                nav.pop()
            }
        }
        dismissAction: ActionItem {
            title: "Cancelar"
            onTriggered:{
               	nav.pop()
            }
        }
    }
    
    // Main container
    Container {
        topPadding: 30
        leftPadding: 30
        rightPadding: 30
        
        // Container with the settings options
        
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Label {
                text: "Mostrar imagen"
                preferredWidth: 500
            }
            ToggleButton {
                id: togImagen
                checked: nav.image.visible
            }
        }
    } 
}
