#ifndef IMAGE_QT_H
#define IMAGE_QT_H

#include "include/image.h"
#include <QImage>
#include <QColor>

#ifdef __cplusplus
extern "C" {
#endif

struct img_rgb_t *
QImage_to_img_rgb
(
    QImage *inImg
);

#ifdef __cplusplus
}
#endif

#endif
