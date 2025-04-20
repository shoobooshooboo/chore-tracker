import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import ChoreTracker

Rectangle {
    id: window
    width: Settings.width
    height: Settings.height
    color: Settings.background_color()

    property var stackViewRef

    Text {
        id:welcome
        anchors.top: parent.top
        anchors.topMargin: 20   // Optional: add margin from the top
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Welcome, ") + Settings.backend.get_user_name()
        color: Settings.text_color()
        font.pointSize: 24
    }



    ScrollView {
                id: scroll
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: welcome.bottom
                anchors.topMargin: 20
                anchors.left: parent.left
                anchors.leftMargin: 100
                width: parent.width * 0.8
                height: parent.height * 0.5


                Column {
                    id: householdsColumn
                    width: parent.width
                    spacing: 16
                    Repeater {
                        model: Settings.backend.householdNames.length


                        Column {
                            spacing: 15
                            padding: 8

                            Button {
                                text: Settings.backend.householdNames[index]
                                width: 200
                                height: 60
                                font.pixelSize: 20
                                padding: 12
                                onClicked: console.log("Clicked:", text)
                            }

                            Text {
                                    text: "Users:"  // Or "Members:"
                                    font.pixelSize: 16
                                    color: Settings.text_color()

                                }

                            // Show users in household
                            Row{
                                spacing: 10
                              Repeater {
                                     model: Settings.backend.householdUsers[index]
                                     delegate: Text {
                                                 text: modelData
                                                 font.pixelSize: 14
                                                 color: Settings.text_color()
                                             }

                                }
                            }

                            Rectangle {
                                width: parent.width
                                height: 1
                                color: "#888"
                            }
                        }
                    }
                }
            }

    // Column{
    //     anchors.centerIn: parent
    //     spacing: 10



    //     Text{
    //         id: counter
    //         anchors.horizontalCenter: parent.horizontalCenter
    //         color: Settings.text_color()
    //         text: Settings.backend.toggledCount
    //     }
    //     Button{
    //         id: button
    //         anchors.horizontalCenter: parent.horizontalCenter
    //         text: qsTr("Toggle dark mode")
    //         onClicked: {
    //             Settings.backend.increment_toggledCount()
    //             Settings.toggle_dark_mode()
    //         }
    //     }
    //     TextField{
    //         id: dynamicTextField
    //         width: 200
    //         text: text
    //         onTextChanged: {
    //                 Qt.callLater(() => Settings.backend.dynamicText = text);
    //             }
    //     }

    //     Button{
    //         id: toHouseholdMenu
    //         anchors.horizontalCenter: parent.horizontalCenter
    //         text: "Go to household page"
    //         onClicked:{
    //             if (stackViewRef){
    //                 stackViewRef.push(Settings.householdWindow)
    //             }
    //             else{
    //                 print("goddamnit")
    //             }
    //         }
    //     }
    // }
}
