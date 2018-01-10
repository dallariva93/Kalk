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
    MODEL/pentagonoregolare.cpp \
    VIEW/colorcreator.cpp\
    VIEW/stylesheet.cpp \
    VIEW/drawarea.cpp \
    VIEW/trianglecreator.cpp \
    VIEW/colorarea.cpp \
    VIEW/quadrilateralcreator.cpp \
    VIEW/pentagoncreator.cpp \
    VIEW/polygoncreator.cpp \
    VIEW/dataarea.cpp \
    VIEW/window.cpp \
    VIEW/operandselector.cpp \
    VIEW/boxbutton.cpp \
    CONTROLLER/controlbuttons.cpp


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
    MODEL/pentagonoregolare.h \
    VIEW/colorcreator.h\
    VIEW/stylesheet.h \
    VIEW/drawarea.h \
    VIEW/trianglecreator.h \
    VIEW/colorarea.h \
    VIEW/quadrilateralcreator.h \
    VIEW/pentagoncreator.h \
    VIEW/polygoncreator.h \
    VIEW/dataarea.h \
    VIEW/window.h \
    VIEW/operandselector.h \
    VIEW/boxbutton.h \
    CONTROLLER/controlbuttons.h
