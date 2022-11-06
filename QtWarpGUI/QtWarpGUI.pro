QT += quick qml
CONFIG += qmltypes

INCLUDEPATH += \
        hdr \
        hdr/controller \
        hdr/common \
        hdr/utils \
        hdr/model

SOURCES += \
        src/AppEngine.cpp \
        src/controller/WarpCliController.cpp \
        src/main.cpp \
        src/common/Constants.cpp \
        src/common/WarpEvents.cpp \
        src/controller/QML_Handler.cpp \
        src/model/AppModel.cpp \
        src/model/SettingsModel.cpp \
        src/model/TabListModel.cpp

HEADERS += \
    hdr/AppEngine.h \
    hdr/common/Common.h \
    hdr/common/Constants.h \
    hdr/common/WarpEvents.h \
    hdr/controller/QML_Handler.h \
    hdr/controller/WarpCliController.h \
    hdr/model/AppModel.h \
    hdr/model/SettingsModel.h \
    hdr/model/TabListModel.h

# Declare QML files
qml_file.files += \
        qml/main.qml \
        qml/components/common/KSwitchButton.qml \
        qml/components/common/KSwitchSetting.qml \
        qml/components/common/KTabItem.qml \
        qml/components/common/KTabIndexer.qml \
        qml/components/KSystemTray.qml \
        qml/components/KTabBar.qml  \
        qml/components/KTabLoader.qml \
        qml/components/KWindow.qml \
        qml/screens/tabs/Warp_HomeTab.qml \
        qml/screens/tabs/Warp_InfoTab.qml \
        qml/screens/tabs/Warp_SetupTab.qml \
        qml/screens/tabs/Warp_UserTab.qml \
        qml/screens/Warp_MainScreen.qml

qml_file.prefix = /$${TARGET}

# Declare image files
img_files.files += \
        res/images/cloudflare.svg   \
        res/images/home.svg         \
        res/images/user.svg         \
        res/images/setup.svg        \
        res/images/info.svg
img_files.prefix = /$${TARGET}

RESOURCES += qml_file img_files

# Set QML_IMPORT_NAME
QML_IMPORT_NAME = com.warp.custom
QML_IMPORT_MAJOR_VERSION = 1
QML_IMPORT_MINOR_VERSION = 0

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    qml/components/common/KButton.qml

