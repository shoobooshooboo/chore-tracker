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

    ListModel{
        id: choresList
    }

    Column{
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Text{
            id: header
            text: qsTr("Household:")
            anchors.horizontalCenter: parent.horizontalCenter
            color: Settings.text_color()
        }

        ScrollView{
            id: choresScrollView
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
                y = header.y + header.height
                height = Settings.height - y
            }
        }
    }
    Button{
        id:backButton
        anchors.horizontalCenter: parent.left + backButton.width / 2
        anchors.verticalCenter: parent.top + backButton.height / 2
        text: qsTr("Back")
        onClicked:{
            if (stackViewRef){
                stackViewRef.pop()
                print("Woo!")
            }else{
                print("Boo!")
            }
        }
    }

    function create_chores_list(): void{
        var choreCount = Settings.backend.get_chores_count()
        for(var i = 0; i < choreCount; i++){
            choresList.append({"name": Settings.backend.get_chore(i)})
        }
    }

    Component.onCompleted:{
        create_chores_list()
    }
}
