/*
 * Copyright (c) 2012 SSP Europe GmbH, Munich
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
 */import bb.cascades 1.0
import "../common"

Page {
    id: createLinkPage
    property int fileId: 0
    resizeBehavior: PageResizeBehavior.Resize
    attachedObjects: [
        // a red tile of 16x16 pixels
        ImagePaintDefinition {
            id: redTile
            repeatPattern: RepeatPattern.XY
            imageSource: "asset:///images/tiles/red16x16.png"
        },
        // recalculate positions
        OrientationHandler {
            onOrientationAboutToChange: {
                if (orientation == UIOrientation.Landscape) {
                    relayout(true)
                } else {
                    relayout(false)
                }
            }
        }
    ]
    actions: [
        ActionItem {
            id: createNowAction
            title: qsTr("Create now") + Retranslate.onLanguageChanged
            // dynamically changed if enabled onRedBarVisible
            enabled: ! folderName.redBarVisible
            imageSource: "asset:///images/upload81.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            // only triggered if enabled if foldertext was entered
            onTriggered: {
                // create the Link
                odsdata.createLink(
                    fileId.valueText, fileName.valueText, 
                    expires.checked, expirationDate.value, 
                    password.text, 
                    linkCode.textFieldText, 
                    noticeDownload.checked)
                // reset fields
                clearFields()
                // automagically close this page
                navigationPane.pop();
            }
        }
    ]
    titleBar: TitleBar {
        id: addBar
        title: qsTr("Create Link") + Retranslate.onLanguageChanged
        visibility: ChromeVisibility.Visible
    }
    Container {
        id: mainContainer
        layout: DockLayout {
        }
        ScrollView {
            //
            //
            Container {
                id: linkContainer
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Top
                layout: StackLayout {
                }
                leftPadding: 40
                rightPadding: 40
                Divider {
                }
                ImageAndLabel {
                    id: fileName
                    imageSource: "../images/files-icon.png"
                }
                
                TextFieldWithMarker {
                    id: linkCode
                    topPadding: 20
                    bottomPadding: 20
                    redBarImage: redTile.image
                    textFieldInputMode: TextFieldInputMode.Text
                    textFieldText: ""
                    textFieldHintText: qsTr("LinkCode (last part of URL)") + Retranslate.onLanguageChanged
                    onRedBarVisibleChanged: {
                        createNowAction.enabled = ! linkCode.redBarVisible
                    }
                }
                TextField {
                    id: password
                    topPadding: 20
                    bottomPadding: 20
                    hintText: qsTr("optional: Password")  + Retranslate.onLanguageChanged;
                    inputMode: TextFieldInputMode.Password
                }
                ToggleButton {
                    id: expires
                    
                }
                DateTimePicker {
                    id: expirationDate
                    visible: expires.checked
                    mode: DateTimePickerMode.Date
                    title: qsTr("Link expires on") + Retranslate.onLanguageChanged
                }
                ToggleButton {
                    id: noticeDownload
                }
                LabelAndLabel {
                    id: fileId
                    labelText: qsTr("File ID") + Retranslate.onLanguageChanged
                }
                Divider {
                }
            } // end Container
        } // end scroll view
    } // end main container
    function clearFields() {
        expires.checked = false
        password.text = ""
        linkCode.textFieldText = ""
        noticeDownload.checked = false
    }
    // set the field values from ODSFolder* data
    function setValues(id, name) {
        clearFields()
        fileName.valueText = name
        fileId.valueText = id
    }
    function refreshData(id, name) {
        setValues(id, name)
    }
    // relayout if orientation changes
    function relayout(landscape) {
        if (landscape == true) {

        } else {

        }
    }
    onCreationCompleted: {
        // initialize positioning
        if (OrientationSupport.orientation == UIOrientation.Landscape) {
            relayout(true)
        }
        clearFields();
    }
}
