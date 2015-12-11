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
    Malloc2D_uchr.c \
    img_rgb_create.c \
    img_rgb_destruct.c \
    Malloc2D_dbl.c \
    map_rgb_create.c \
    map_rgb_destruct.c \
    QImage_to_img_rgb.cpp \
    img_to_map_rgb.c \
    map_to_img_rgb.c \
    TSV_inPaint.cpp \
    map_create.c \
    map_destruct.c \
    img_rgb_to_QImage.cpp

HEADERS  += include/image.h \
    include/image_qt.h
