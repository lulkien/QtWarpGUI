QT += quick qml
CONFIG += qmltypes

#DEFINES += WARP_DEBUG
DEFINES += USING_OSD_ANIMATION

INCLUDEPATH += \
        hdr \
        hdr/controller \
        hdr/common \
        hdr/model \
        hdr/utils

SOURCES += \
        src/AppEngine.cpp \
        src/controller/OSD_Controller.cpp \
        src/controller/WarpCliController.cpp \
        src/main.cpp \
        src/common/Constants.cpp \
        src/controller/QML_Handler.cpp \
        src/model/ApplicationModel.cpp \
        src/model/QML_Model.cpp \
        src/model/TabListModel.cpp \
        src/utils/Translator.cpp

HEADERS += \
    hdr/AppEngine.h \
    hdr/common/Common.h \
    hdr/common/Constants.h \
    hdr/common/WarpEnums.h \
    hdr/controller/OSD_Controller.h \
    hdr/controller/QML_Handler.h \
    hdr/controller/WarpCliController.h \
    hdr/model/ApplicationModel.h \
    hdr/model/QML_Model.h \
    hdr/model/TabListModel.h \
    hdr/utils/Translator.h

# Declare QML files
qml_file.files += \
        qml/components/common/KButton.qml \
        qml/components/common/KSwitchButton.qml \
        qml/components/common/KSwitchSetting.qml \
        qml/components/common/KTabItem.qml \
        qml/components/common/KTabIndexer.qml \
        qml/components/KSystemTray.qml \
        qml/components/KTabBar.qml  \
        qml/components/KTabLoader.qml \
        qml/components/KWindow.qml \
        qml/main.qml \
        qml/screens/OSDs/Warp_OSD_StartService.qml \
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
        res/images/info.svg         \
        res/images/setup.svg        \
        res/images/power.svg        \
        res/images/user.svg
img_files.prefix = /$${TARGET}

# Declare translation qm files
trans.files += \
        res/translations/qm/en_US.qm
trans.prefix = /$${TARGET}

RESOURCES += qml_file img_files trans

# Declare translation ts files
TRANSLATIONS += \
        res/translations/ts/en_US.ts

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

DISTFILES +=

