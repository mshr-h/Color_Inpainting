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
    lib_c/img_rgb_create.c \
    lib_c/img_rgb_destruct.c \
    lib_c/img_to_map_rgb.c \
    lib_c/Malloc2D_dbl.c \
    lib_c/Malloc2D_uchr.c \
    lib_c/map_create.c \
    lib_c/map_destruct.c \
    lib_c/map_rgb_create.c \
    lib_c/map_rgb_destruct.c \
    lib_c/map_to_img_rgb.c \
    lib_c/TSV_Inpaint.c \
    lib_qc/img_rgb_to_QImage.cpp \
    lib_qc/QImage_to_img_rgb.cpp

HEADERS  += include/image.h \
    include/image_qt.h
