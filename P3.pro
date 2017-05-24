#-------------------------------------------------
#
# Project created by QtCreator 2017-04-12T17:29:35
#
#-------------------------------------------------

QT       += core gui opengl
LIBS += -lopengl32
QT += core gui

LIBS     += -lopengl32 -LC:/assimp/code/ -lassimp
INCLUDEPATH +=  C:/assimp/include/
DEPENDPATH  +=  C:/assimp/include/


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = P3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    myglwidget.cpp \
    modelloader.cpp \
    planets.cpp


HEADERS  += mainwindow.h \
    myglwidget.h \
    modelloader.h \
    planets.h

FORMS    += mainwindow.ui

DISTFILES += \
    P3_models/sphere_low.obj \
    P3_models/bunny.obj

RESOURCES += \
    shader.qrc

