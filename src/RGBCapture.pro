QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main/captureHelpers/captureactivemonitor.cpp \
    main/captureHelpers/captureactivewindow.cpp \
    main/captureHelpers/capturecustomregion.cpp \
    main/captureHelpers/capturecustomwindow.cpp \
    main/captureHelpers/capturefullscreen.cpp \
    main/captureHelpers/capturelastregion.cpp \
    main/captureHelpers/capturemonitor.cpp \
    main/captureHelpers/captureregion.cpp \
    main/captureHelpers/capturewindow.cpp \
    main/main.cpp \
    main/mainleftmenu.cpp \
    main/mainwindow.cpp \
    main/captureHelpers/capturebase.cpp \
    main/systemtrayicon.cpp \
    main/taskhelpers.cpp \
    main/taskmetadata.cpp \
    main/tasksettings.cpp \
    main/menuitem.cpp \
    helpers/helpers/capturehelpers.cpp \
    helpers/helpers/helpers.cpp \
    helpers/externalprogram.cpp \
    helpers/native/windowInfo.cpp \
    helpers/helpers/mathhelpers.cpp \
    helpers/native/nativemethods_helpers.cpp \
    screenCapture/screenshot.cpp \


HEADERS += \
    main/captureHelpers/captureactivemonitor.h \
    main/captureHelpers/captureactivewindow.h \
    main/captureHelpers/capturebase.h \
    main/captureHelpers/capturecustomregion.h \
    main/captureHelpers/capturecustomwindow.h \
    main/captureHelpers/capturefullscreen.h \
    main/captureHelpers/capturelastregion.h \
    main/captureHelpers/capturemonitor.h \
    main/captureHelpers/captureregion.h \
    main/captureHelpers/capturewindow.h \
    main/enums.h \
    main/mainleftmenu.h \
    main/mainwindow.h \
    main/menuitem.h \
    main/systemtrayicon.h \
    main/taskhelpers.h \
    main/taskmetadata.h \
    main/tasksettings.h \
    main/watchfoldersettings.h \
    helpers/enums.h \
    helpers/externalprogram.h \
    helpers/helpers/capturehelpers.h \
    helpers/helpers/helpers.h \
    helpers/helpers/mathhelpers.h \
    helpers/native/nativemethods_helpers.h \
    helpers/native/windowInfo.h \
    screenCapture/enums.h \
    screenCapture/regioncaptureoptions.h \
    screenCapture/screenshot.h \
    uploaders/enums.h \


FORMS += \
    main/mainwindow.ui

TRANSLATIONS += \
    RGBCapture_zh_CN.ts

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    RGBCapture.qrc
