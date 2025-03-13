import QtQuick
import QtQuick.Controls.Basic
import testv3

Window {
    width: 640
    height: 480
    visible: true
    color: Settings.background_color()
    property int timesClicked: 0
    title: qsTr("Hello World")

    Backend{
        id:backend
    }

    Column{
        anchors.centerIn: parent
        spacing: 10
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            color: Settings.text_color()
            text: backend.testText
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Toggle dark mode")
            onClicked: backend.change_text(timesClicked++)

        }
    }
}
