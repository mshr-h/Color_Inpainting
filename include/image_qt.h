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

struct img_rgb_t *
TSV_inPaint_rgb
(
    struct img_rgb_t *in_rgb,
    struct img_rgb_t *msk_rgb
);

#ifdef __cplusplus
}
#endif

#endif
