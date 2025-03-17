import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import ChoreTracker

Window {
    id: window
    width: 640
    height: 480
    visible: true
    color: Settings.background_color()
    title: qsTr("Hello World")

    Backend{
        id:backend
    }

    ListModel{
        id: choresList
    }

    Column{
        anchors.centerIn: parent
        spacing: 10
        Text{
            id: counter
            anchors.horizontalCenter: parent.horizontalCenter
            color: Settings.text_color()
            text: backend.toggledCount
        }
        Button{
            id: button
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Toggle dark mode")
            onClicked: {
                backend.increment_toggledCount()
                Settings.toggle_dark_mode()
            }
        }
        ScrollView{
            height: 200
            ScrollBar.vertical.interactive: true
            ListView{
                model: choresList
                spacing: 10
                delegate: Row{
                    Text {
                        text: name
                        color: Settings.text_color()
                    }
                }
            }
            Component.onCompleted: {
                y = button.y + button.height
            }
        }
    }

    function create_chores_list(): void{
        var choreCount = backend.get_chores_count()
        for(var i = 0; i < choreCount; i++){
            choresList.append({"name": backend.get_chore(i)})
        }
    }

    Component.onCompleted:{
        create_chores_list()
    }
}
