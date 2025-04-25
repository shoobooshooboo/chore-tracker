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


    Text{
        id: header
        font.pointSize: 20
        text: qsTr(Settings.backend.curHouseholdName)
        anchors.horizontalCenter: parent.horizontalCenter
        color: Settings.text_color()
    }

    ScrollView{
        id: scroll
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: header.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 100
        width: parent.width
        height: parent.height - header.height - 40

        Column{
            id: choresColumn
            width: parent.width
            spacing: 16

            Repeater{
                model: Settings.backend.choreNames.length

                Column{
                    Button{
                        text: qsTr(Settings.backend.choreNames[index])
                        width: 200
                        height: 60
                        font.pixelSize: 20
                        padding: 12
                        onClicked: {
                            print("should happen")
                        }
                    }
                    Text{
                        text: qsTr(Settings.backend.choreLocations[index])
                        font.pixelSize: 13
                    }
                    Text{
                        text: qsTr(Settings.backend.choreDates[index])
                        font.pixelSize: 13
                    }
                    CheckBox{
                        text: qsTr("Completed")
                        checked: Settings.backend.choreStatuses[index]
                        onCheckedChanged: {
                            Settings.backend.set_chore_status(index, checked)
                        }
                    }
                }
            }
        }
    }
    Button{
        id:backButton
        text: qsTr("Back")
        onClicked:{
            if (stackViewRef)
                stackViewRef.pop()
        }
    }
    Button{
        id:addChoreButton
        anchors.top: parent.top
        anchors.right: parent.right
        width: Qt.callLater(() => backButton.width)
        height: Qt.callLater(() => backButton.height)
        text: qsTr("+")
        font.pixelSize: 40
        onClicked:{
            if(stackViewRef)
                stackViewRef.push(Settings.createChoreWindow)
        }
    }
}
