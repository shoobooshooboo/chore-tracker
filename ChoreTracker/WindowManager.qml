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
    }

    Component.onCompleted:{
        Settings.mainWindow.stackViewRef = stackView
        Settings.householdWindow.stackViewRef = stackView
        Settings.createChoreWindow.stackViewRef = stackView
        Settings.editChoreWindow.stackViewRef = stackView
        stackView.push(Settings.mainWindow)
    }
}
