#-------------------------------------------------
#
# Project created by QtCreator 2021-10-25T18:26:45
#
#-------------------------------------------------

QT       += core gui sql network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CentralControl
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
QMAKE_CXXFLAGS_RELEASE = -Od -ZI -MD
QMAKE_LFLAGS_RELEASE = /DEBUG /INCREMENTAL:NO

SOURCES += \
        centralwidget.cpp \
        circlewidget.cpp \
        gdatafactory.cpp \
        leftwidget.cpp \
        main.cpp \
        mainwindow.cpp \
        mesprocess.cpp \
        onebuttonchangewidget.cpp \
        rightheadwidget.cpp \
        rightmainwidget.cpp \
        rightmainwindow.cpp \
        rightquerywidget.cpp \
        testwidget.cpp \
        title/TitleBar.cpp \
        title/titlewidget.cpp \
        welcomewidget.cpp

HEADERS += \
        centralwidget.h \
        circlewidget.h \
        gdatafactory.h \
        leftwidget.h \
        mainwindow.h \
        mesprocess.h \
        onebuttonchangewidget.h \
        rightheadwidget.h \
        rightmainwidget.h \
        rightmainwindow.h \
        rightquerywidget.h \
        testwidget.h \
        title/TitleBar.h \
        title/titlewidget.h \
        welcomewidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += .\title

INCLUDEPATH += ..\..\AppearanceDetectProMaterials\QsLog-master
INCLUDEPATH += ..\..\AppearanceDetectProMaterials\DMDBAccess

DEFINES += QSLOG_IS_SHARED_LIBRARY_IMPORT
DEFINES += QS_LOG_LINE_NUMBERS

LIBS += -L$$PWD\lib\x64\ -lQsLog2
LIBS += -L$$PWD\lib\x64\ -lDMDBAccess

RESOURCES += \
    rc.qrc
