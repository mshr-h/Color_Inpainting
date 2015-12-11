#ifndef IMAGE_H
#define IMAGE_H

#include <stdlib.h>
#include <stdio.h>

struct img_t
{
    int wt;
    int ht;
    unsigned char **data;
};

struct img_rgb_t
{
    int wt;
    int ht;

    unsigned char **r;
    unsigned char **g;
    unsigned char **b;
};

struct img_yuv_t
{
    int wt;
    int ht;

    unsigned char **y;
    unsigned char **u;
    unsigned char **v;
};

struct map_t
{
    int wt;
    int ht;
    double **data;
};

struct map_rgb_t
{
    int wt;
    int ht;
    double **r;
    double **g;
    double **b;
};

struct map_yuv_t
{
    int wt;
    int ht;
    double **y;
    double **u;
    double **v;
};

// function prototype
#ifdef __cplusplus
extern "C" {
#endif

unsigned char **
Malloc2D_uchr
(
    int wt,
    int ht,
    unsigned char init
);

double **
Malloc2D_dbl
(
    int wt,
    int ht,
    double init
);

struct img_rgb_t *
img_rgb_create
(
    int wt,
    int ht,
    unsigned char init
);

void
img_rgb_destruct
(
    struct img_rgb_t *img
);

struct map_t *
map_create
(
    int wt,
    int ht,
    double init
);

struct map_rgb_t *
map_rgb_create
(
    int wt,
    int ht,
    double init
);

void
map_destruct
(
    struct map_t *map
);

void
map_rgb_destruct
(
    struct map_rgb_t *map
);

struct map_rgb_t *
img_to_map_rgb
(
    struct img_rgb_t *in
);

struct img_rgb_t *
map_to_img_rgb
(
    struct map_rgb_t *map
);

#ifdef __cplusplus
}
#endif

#endif // IMAGE_H
