QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    capturebase.cpp \
    capturehelpers.cpp \
    helpers.cpp \
    helpers/externalprogram.cpp \
    helpers/native/windowInfo.cpp \
    main.cpp \
    mainleftmenu.cpp \
    mainwindow.cpp \
    mathhelpers.cpp \
    menuitem.cpp \
    nativemethods_helpers.cpp \
    screenshot.cpp \
    systemtrayicon.cpp \
    taskmetadata.cpp \
    tasksettings.cpp

HEADERS += \
    capturebase.h \
    capturehelpers.h \
    enums.h \
    helpers.h \
    helpers/enums.h \
    helpers/externalprogram.h \
    helpers/native/windowInfo.h \
    mainleftmenu.h \
    mainwindow.h \
    mathhelpers.h \
    menuitem.h \
    nativemethods_helpers.h \
    screenshot.h \
    systemtrayicon.h \
    taskmetadata.h \
    tasksettings.h \
    uploaders/enums.h \
    watchfoldersettings.h

FORMS += \
    mainwindow.ui

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
