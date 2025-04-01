import QtQuick
import QtQuick.Controls
import ChoreTracker

ApplicationWindow {
    visible: true
    width: Settings.width
    height: Settings.height

    StackView{
        id: stackView
        anchors.fill: parent
        initialItem: mainWindowComponent
    }

    Rectangle {
        id: mainWindowComponent
        Main{stackViewRef: stackView}
    }
}
