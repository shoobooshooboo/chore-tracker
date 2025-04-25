pragma Singleton
import QtQuick

QtObject {
    property bool darkMode: false
    property int height: 896
    property int width: 414
    property Backend backend: new Backend()
    property var mainWindow: Main{}
    property var householdWindow: Household{}
    property var createChoreWindow: CreateChore{}

    function background_color(){
        return darkMode ? "#000000" : "#ffffff"
    }

    function text_color(){
        return darkMode ? "#ffffff" : "#000000"
    }

    function toggle_dark_mode(){
        darkMode = !darkMode
    }


}
