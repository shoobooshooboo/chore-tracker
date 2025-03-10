pragma Singleton
import QtQuick

QtObject {
    property bool darkMode: true

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
