// QT Classes
import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

// Our own QT Classes

// --- Main GUI Window
Window {
    signal connectSfu(string url, string id)

  // --- properties / members

  id: root       // id for reference by other QML objects

  visible: true  // wether the windows is visible

  width:  1280
  height: 1280

  title: qsTr("DM sfu client")

  Button {
      id: button
      x: 177
      y: 623
      text: qsTr("Button")
      onClicked: {
          console.log("Button pressed");
          connectSfu("aaa", "bbb");
      }
  }
}
