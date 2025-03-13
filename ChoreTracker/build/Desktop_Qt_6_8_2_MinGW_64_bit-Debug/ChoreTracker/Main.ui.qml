import QtQuick
import QtQuick.Controls.Basic
import testv3

Window {
    width: 640
    height: 480
    visible: true
    color: Settings.background_color()
    title: qsTr("Hello World")

    Column{
        anchors.centerIn: parent
        spacing: 10
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            color: Settings.text_color()
            text: qsTr("Hello text!")
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Toggle dark mode")

            onClicked: Settings.toggle_dark_mode()
        }
    }
}
