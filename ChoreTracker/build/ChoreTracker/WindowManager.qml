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
        //initialItem: Settings.mainWindow
    }

    Component.onCompleted:{
        Settings.mainWindow.stackViewRef = stackView
        Settings.householdWindow.stackViewRef = stackView
        stackView.push(Settings.mainWindow)
    }
}
