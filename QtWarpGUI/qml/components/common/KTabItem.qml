import QtQuick 2.15

Item {
    id: root_tabItem
    width: Constants.TAB_SIZE
    height: Constants.TAB_SIZE

    property bool showSpacer: true

    Rectangle {
        id: spacer
        visible: root_tabItem.showSpacer
        anchors {
            bottom: root_tabItem.bottom
            horizontalCenter: root_tabItem.horizontalCenter
        }
        height: 1
        width: root_tabItem.width * 0.8
        color: Constants.BLACK
    }
}
