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

    Column{
        anchors.centerIn: parent
        spacing: 10


        Text{
            id: counter
            anchors.horizontalCenter: parent.horizontalCenter
            color: Settings.text_color()
            text: Settings.backend.toggledCount
        }
        Button{
            id: button
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Toggle dark mode")
            onClicked: {
                Settings.backend.increment_toggledCount()
                Settings.toggle_dark_mode()
            }
        }
        TextField{
            id: dynamicTextField
            width: 200
            text: text
            onTextChanged: {
                    Qt.callLater(() => Settings.backend.dynamicText = text);
                }
        }

        Button{
            id: toHouseholdMenu
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Go to household page"
            onClicked:{
                if (stackViewRef){
                    stackViewRef.push(Settings.householdWindow)
                }
                else{
                    print("goddamnit")
                }
            }
        }
    }
}
