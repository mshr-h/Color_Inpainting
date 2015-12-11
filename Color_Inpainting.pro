#-------------------------------------------------
#
# Project created by QtCreator 2015-12-11T23:50:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Color_Inpainting
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    Malloc2D_uchr.c \
    img_rgb_create.c \
    img_rgb_destruct.c \
    Malloc2D_dbl.c \
    map_rgb_create.c \
    map_rgb_destruct.c \
    QImage_to_img_rgb.cpp \
    img_to_map_rgb.c \
    map_to_img_rgb.c

HEADERS  += include/mainwindow.h \
            include/image.h \
    include/image_qt.h

FORMS    += lib_ui/mainwindow.ui
