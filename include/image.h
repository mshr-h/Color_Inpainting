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

#ifdef __cplusplus
}
#endif

#endif // IMAGE_H
