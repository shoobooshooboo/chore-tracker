import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import ChoreTracker

Rectangle {
    id: window
    width: Settings.width
    height: Settings.height
    color: Settings.background_color()
    // title: qsTr("Hello World")
    // visible: true

    property var stackViewRef



    Column{
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20

        Text{
            id: header
            font.pointSize: 20
            text: qsTr("Create chore")
            anchors.horizontalCenter: parent.horizontalCenter
            color: Settings.text_color()
        }

        TextField{
            id: name
            font.pointSize: 15
            placeholderText: qsTr("Chore name")
        }

        TextField{
            id: location
            font.pointSize: 15
            placeholderText: qsTr("Location")
        }

        Column{
            Text{
                text: qsTr("Due Date")
                font.pointSize: 15
            }
            TextField{
                id: dueDate
                font.pointSize: 15
                validator: RegularExpressionValidator{regularExpression: /^(\d{4})-(0[1-9]|1[0-2]|[1-9])-([1-9]|0[1-9]|[1-2]\d|3[0-1])$/}
                placeholderText: qsTr("YYYY-MM-DD")
            }
        }

        Column{
            CheckBox{
                id: doesReccur
                text: qsTr("recurrs")
                font.pointSize: 15
            }
            TextField{
                id: recurrance
                readOnly: !doesReccur.checked
                font.pointSize: 15
                validator: IntValidator{bottom: 1}
                placeholderText: qsTr("every x Days")
            }
        }
    }

    Button{
        id:backButton
        text: qsTr("Cancel")
        onClicked:{
            if (stackViewRef)
                stackViewRef.pop()
        }
    }
    Button{
        id:doneButton
        anchors.top: parent.top
        anchors.right: parent.right
        width: Qt.callLater(() => backButton.width)
        height: Qt.callLater(() => backButton.height)
        text: qsTr("Confirm")
        font.pixelSize: 30
        onClicked:{
            Settings.backend.edit_chore(name.text, location.text, dueDate.text, doesReccur.checked, recurrance.text)
            if(stackViewRef)
                stackViewRef.pop()
        }
    }

    function prep(){
        name.text = Settings.backend.choreNames[Settings.backend.curChoreIndex]
        location.text = Settings.backend.choreLocations[Settings.backend.curChoreIndex]
        dueDate.text = Settings.backend.choreDueDates[Settings.backend.curChoreIndex]
        doesReccur.checked = Settings.backend.choreDoesReccurs[Settings.backend.curChoreIndex]
        recurrance.text = Settings.backend.choreReccurances[Settings.backend.curChoreIndex]
    }
}
