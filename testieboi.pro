#-------------------------------------------------
#
# Project created by QtCreator 2021-01-26T19:57:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testieboi
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

#---CERN ROOT---
linux-g++ || unix {
     INCLUDEPATH += $$system(root-config --incdir)
     LIBS += $$system(root-config --libs) -lGeom -lGeomPainter -lGeomBuilder -lMinuit2 -lSpectrum -ltbb
     ants2_RootServer {LIBS += -lRHTTP  -lXMLIO}
}
win32 {
     INCLUDEPATH += c:/root/include
     LIBS += -Lc:/root/lib/ -llibCore -llibRIO -llibNet -llibHist -llibGraf -llibGraf3d -llibGpad -llibTree -llibRint -llibPostscript -llibMatrix -llibPhysics -llibMathCore -llibGeom -llibGeomPainter -llibGeomBuilder -llibMinuit2 -llibThread -llibSpectrum
     ants2_RootServer {LIBS += -llibRHTTP}
}
#-----------

SOURCES += \
        main.cpp \
        mainwindowo.cpp

HEADERS += \
        mainwindowo.h

FORMS += \
        mainwindowo.ui
