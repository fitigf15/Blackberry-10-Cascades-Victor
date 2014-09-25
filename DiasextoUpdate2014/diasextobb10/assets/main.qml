import bb.cascades 1.0
import bb.system 1.0
import bb.multimedia 1.0
NavigationPane {
    id: nav
    property alias image : imagen
    Menu.definition: MenuDefinition{
        actions: [
            
            //The info item
            
            ActionItem {
                title: "Información"
                imageSource: "asset:///images/info.png"
                onTriggered: {
                    toast.body= "Esta aplicación ha sido diseñada a partir del blog de Dia Sexto con fin de promocionar su música sin ánimo de lucro.\n Autor: stackmelol\n Contacto: fiti.gf15@gmail.com"
                    toast.show()
                }
            },
            
            //The help item
            
            ActionItem  {
                title: "Ayuda"
                imageSource: "asset:///images/help.png"
                onTriggered: {
                    toast.body= "Cuando pulses el nombre de una canción o de un vídeo se abrirá una ventana preguntando por qué hacer. \n Se puede compartir y descargar la url del archivo. \n En el apartado de discos se puede seleccionar el disco del que queremos ver las canciones. \n En la barra de la derecha tenemos todas las páginas oficiales de Día Sexto."
                    toast.show()
                }
            },
            
            //The settings item
            
            ActionItem {
                title: "Configuración"
                onTriggered: {
                    nav.push(settings.createObject())
                
                }
            }
        
        ]
    }
    
    
    
    firstPage: Page {
        
        //Attached objects
        
        attachedObjects: [
            
            //Settings page
            
            ComponentDefinition {
                source: "asset:///Settings.qml"
                id: settings
            },
            
            
            //Dialog used to manage the song or video url
            
            SystemProgressDialog {
                title: "Qué hacer con:"
                id: manageDialog
                
                confirmButton{
                    label: "Compartir"
                }
                customButton{
                    label: "Reproducción"
                }
                cancelButton{
                    label: "Atrás"
                }
                onFinished: {
                    if(buttonSelection()==confirmButton){
                        shareInvoke.trigger("bb.action.SHARE")
                    }
                    if(buttonSelection()==customButton){
                        toast.body="Reproduciendo "+body
                        toast.show()
                    }
                }
            },
            
            //Dialog used to invoke the browser
            
            SystemProgressDialog {
                title: "Se abrirá el navegador con la url:"
                id: dialogNavegador
                confirmButton.label: "Aceptar"
                cancelButton.label: "Cancelar"
                onFinished: {
                    if(buttonSelection()==confirmButton){
                        urlInvoke.trigger("bb.action.OPEN")
                    }
                }
            },
            
            //Information toast
            
            SystemToast {
                id: toast
                
                button.label: "aceptar"
            },
            
            //Invocation used to share content
            
            Invocation {
                id: shareInvoke
                query{
                    mimeType: "text/plain"
                    invokeActionId: "bb.action.SHARE"
                    invokerIncluded: true
                    onDataChanged: {
                        shareInvoke.query.updateQuery()
                    }
                }
            },
            
            //Invocation used to open browser
            
            Invocation {
                id: urlInvoke
                query{
                    invokeTargetId: "sys.browser"
                    invokeActionId: "bb.action.OPEN"
                    onQueryChanged: {
                        urlInvoke.query.updateQuery()
                    }
                
                }
            },MediaPlayer {
                id: player
                // Set these properties for video
                videoOutput: VideoOutput.PrimaryDisplay
                
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
        
        //Action items
        actions: [
            
            //Information action item
            
            ActionItem {
                title: "Información"
                imageSource: "asset:///images/info.png"
                onTriggered: {
                	toast.body= "Esta aplicación ha sido diseñada a partir del blog de Dia Sexto con fin de promocionar su música sin ánimo de lucro.\n Autor: stackmelol\n Contacto: fiti.gf15@gmail.com"
                    toast.show()
                }
                ActionBar.placement: ActionBarPlacement.OnBar
            },
            
            //Official webpages action items
            
            ActionItem {
                imageSource: "asset:///images/blogspot.jpg"
                title: "Blog Fan de Dia Sexto"
                onTriggered: {
                    urlInvoke.query.uri="http://diasexto.blogspot.com.es/"
                    urlInvoke.query.uriChanged("http://diasexto.blogspot.com.es/")
                    dialogNavegador.body="http://diasexto.blogspot.com.es/"
                    dialogNavegador.show()
                }
            },ActionItem {
                title: "Web de Dia Sexto"
                imageSource: "asset:///images/web.jpg"
                onTriggered: {
                    urlInvoke.query.uri="http://www.diasexto.es/#NOVEDADES"
                    urlInvoke.query.uriChanged("http://www.diasexto.es/#NOVEDADES")
                    dialogNavegador.body="http://www.diasexto.es/#NOVEDADES"
                    dialogNavegador.show()
                }
            },ActionItem {
                title: "Facebook de Dia Sexto"
                imageSource: "asset:///images/facebook.png"
                onTriggered: {
                    urlInvoke.query.uri="https://www.facebook.com/pages/Dia-Sexto/165542223483754"
                    urlInvoke.query.uriChanged("https://www.facebook.com/pages/Dia-Sexto/165542223483754")
                    dialogNavegador.body="https://www.facebook.com/pages/Dia-Sexto/165542223483754"
                    dialogNavegador.show()
                }
            },ActionItem {
                title: "Twitter de Dia Sexto"
                imageSource: "asset:///images/twitter-logo.png"
                onTriggered: {
                    urlInvoke.query.uri="https://twitter.com/Diasexto86"
                    urlInvoke.query.uriChanged("https://twitter.com/Diasexto86")
                    dialogNavegador.body="https://twitter.com/Diasexto86"
                    dialogNavegador.show()
                }
            },ActionItem {
                title: "Youtube de Dia Sexto"
                imageSource: "asset:///images/youtube.jpg"
                onTriggered: {
                    urlInvoke.query.uri="http://www.youtube.com/user/diasexto"
                    urlInvoke.query.uriChanged("http://www.youtube.com/user/diasexto")
                    dialogNavegador.body="http://www.youtube.com/user/diasexto"
                    dialogNavegador.show()
                }
            },ActionItem {
                title: "Reproducción"
                imageSource: "asset:///images/play.png"
                ActionBar.placement: ActionBarPlacement.OnBar
                onTriggered: {
                    if (player.speed>0) {
                        player.pause()
                    }else {
                        player.play()
                    }
                }
              }
        ]
        
        //Main container
        
        Container {
            
            // Giving a bit of padding improving visual sensation
            topPadding: 30
            leftPadding: 30
            rightPadding: 30
            bottomPadding: 30
            
            //Image only displayed in 768x1280
            
            Container {
                preferredHeight: 560
                Imagen {
                    id: imagen
                    visible: true
                }
                
            }
            
            Container {
                preferredHeight: 500
                //Segmented control to select the type of indexPath
                
                SegmentedControl {
                    selectedIndex: 0
                    onSelectedIndexChanged: {
                        listFiles.clearSelection()
                        if (selectedIndex==0){
                            contDiscs.visible=false
                            divAltres.visible=true
                            listFiles.rootIndexPath=[0]
                        } else if(selectedIndex==1){
                            contDiscs.visible=true
                            divAltres.visible=false
                            dropDiscs.selectedIndex=0
                            listFiles.rootIndexPath=[1,0]
                        } else if (selectedIndex==2){
                            divAltres.visible=true
                            contDiscs.visible=false
                            listFiles.rootIndexPath=[2]
                        } else if (selectedIndex==3){
                            divAltres.visible=true
                            contDiscs.visible=false
                            listFiles.rootIndexPath=[3]
                        }
                    }
                    options: [
                        Option {
                            text: "Nuevo"
                        },Option {
                            text: "Discos"
                        },Option {
                            text: "Inédito"
                        },Option {
                            text: "Otros"
                        }]
                }
                
                //Divider visible on indexPaths [0],[2],[3]
                
                Divider {
                    id: divAltres
                    visible: true
                    preferredHeight: 90
                }
                
                //Container visible on indexPaths [1,X]
                
                Container {
                    preferredHeight: 90
                    id: contDiscs
                    visible: false
                    //Dropdown to select the X indexPath of [1,X]
                    
                    DropDown {
                        id: dropDiscs
                        selectedIndex: 0
                        title: "Álbum"
                        onSelectedIndexChanged: {
                            listFiles.rootIndexPath=[1,selectedIndex]
                            //checkCd.checked=false
                            listFiles.clearSelection()
                        }
                        options: [
                            Option {
                                text: "Rarezas"
                            },Option {
                                text: "Rap-Art (2006)"
                            },Option {
                                text: "2.0.0.8"
                            },Option {
                                text: "Fibra Sensible (2009)"
                            },Option {
                                text: "R-Evolución (2010)"
                            },Option {
                                text: "El secreto de Ki.En.Gi. (2011)"
                            },Option {
                                text: "Tiempos de Cambio (2012)"
                            }]
                    } 
                }
                
                //ListView containing the name of the songs or videos with their urls
                
                ListView {
                    id: listFiles
                    rootIndexPath: [ 0 ]
                    dataModel: XmlDataModel {
                        source: "asset:///models/urls.xml"
                    }
                    onTriggered: {
                        var chosenItem = dataModel.data(indexPath)
	            		 manageDialog.body=chosenItem.title
	                     manageDialog.show()
	                     dialogNavegador.body=chosenItem.url
	                     urlInvoke.query.uri=chosenItem.url
	                     urlInvoke.query.uriChanged(chosenItem.url)
	                     shareInvoke.query.data="He escuchado la cancion "+chosenItem.title+" de Dia Sexto, la descargue de "+chosenItem.url
	                     shareInvoke.query.dataChanged("He escuchado la cancion "+chosenItem.title+", de Dia Sexto la descargue de "+chosenItem.url)
                         player.sourceUrl=chosenItem.url
                    }
                    listItemComponents: [
                        ListItemComponent {
                            type: "song"
                            Container {
                                topPadding: 30
                                preferredHeight: 90
                                ScrollView {
                                    scrollViewProperties.scrollMode: ScrollMode.Horizontal
                                    Label {
                                        text: ListItemData.title
                                        textStyle.textAlign: TextAlign.Center
                                    }
                                }
                            }
                        }]
                
                }
                
                Button {
                    preferredHeight: 45
                    preferredWidth: 45
                    horizontalAlignment: HorizontalAlignment.Center
                    text: "^	Toca para para recoger	^"
                }
            }
            
            Container {
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
                        preferredWidth: 90
                    }
                    Label {
                        text: ""
                        preferredWidth: 528
                    }
                    Label {
                        text: Math.floor(((((player.duration / 1000) % 31536000) % 86400) % 3600) / 60) + ":" + Math.floor(((((player.duration / 1000) % 31536000) % 86400) % 3600) % 60)
                        horizontalAlignment: HorizontalAlignment.Right
                        preferredWidth: 90
                        textStyle.textAlign: TextAlign.Right
                    
                    }
                }
                /*
                
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
                */
            }
        }
    }
}
