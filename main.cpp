#include "include/image.h"
#include "include/image_qt.h"
#include "include/mainwindow.h"

int main(int argc, char *argv[])
{
    if(argc < 4) {
        printf("./Color_Inpainting grayscale.png mask.png out.png\n");
        //return 0;
    }

    auto in = QImage_to_img_rgb(new QImage(argv[1]));
    auto msk = QImage_to_img_rgb(new QImage(argv[2]));

    auto out = TSV_inPaint_rgb(in,msk);

    auto outImg = img_rgb_to_QImage(out);

    outImg.save(argv[3], "PNG");

    img_rgb_destruct(in);
    img_rgb_destruct(msk);
    img_rgb_destruct(out);

    return 0;
}
