#include "include/image.h"
#include "include/image_qt.h"
#include "include/mainwindow.h"

int main(int argc, char *argv[])
{
    if(argc < 4) {
        printf("./Color_Inpainting grayscale.png mask.png out.png\n");
        //return 0;
    }

    auto in_img_rgb = QImage_to_img_rgb(new QImage("Lvn_kid_gs.png"));
    img_rgb_destruct(in_img_rgb);

    return 0;
}
