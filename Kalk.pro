#-------------------------------------------------
#
# Project created by QtCreator 2017-12-04T15:15:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kalk
TEMPLATE = app


SOURCES += main.cpp \
    MODEL/rgb.cpp \
    MODEL/colore.cpp \
    MODEL/punto.cpp \
    MODEL/angolo.cpp \
    MODEL/poligono.cpp \
    MODEL/triangolo.cpp \
    MODEL/quadrilatero.cpp \
    MODEL/pentagono.cpp \
    MODEL/quadrato.cpp \
    MODEL/rettangolo.cpp \
    VIEW/colorcreator.cpp\
    VIEW/drawarea.cpp \
    VIEW/trianglecreator.cpp \
    VIEW/quadrilateralcreator.cpp \
    VIEW/pentagoncreator.cpp \
    VIEW/polygoncreator.cpp \
    VIEW/dataarea.cpp \
    VIEW/window.cpp \
    VIEW/operandselector.cpp \
    VIEW/boxbutton.cpp \
    CONTROLLER/controlbuttons.cpp \
    MODEL/container.cpp \
    VIEW/exception.cpp


HEADERS  += \
    MODEL/rgb.h \
    MODEL/colore.h \
    MODEL/punto.h \
    MODEL/angolo.h \
    MODEL/poligono.h \
    MODEL/triangolo.h \
    MODEL/quadrilatero.h \
    MODEL/pentagono.h \
    MODEL/quadrato.h \
    MODEL/rettangolo.h \
    VIEW/colorcreator.h\
    VIEW/drawarea.h \
    VIEW/trianglecreator.h \
    VIEW/quadrilateralcreator.h \
    VIEW/pentagoncreator.h \
    VIEW/polygoncreator.h \
    VIEW/dataarea.h \
    VIEW/window.h \
    VIEW/operandselector.h \
    VIEW/boxbutton.h \
    CONTROLLER/controlbuttons.h \
    MODEL/container.h \
    VIEW/exception.h

