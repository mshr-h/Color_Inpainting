#include "include/image.h"
#include "include/image_qt.h"

int main(int argc, char *argv[])
{
    if(argc < 4) {
        printf("./Color_Inpainting grayscale.png mask.png out.png\n");
        return 0;
    }

    auto in = QImage_to_img_rgb(new QImage(argv[1]));
    auto msk = QImage_to_img_rgb(new QImage(argv[2]));

    int it=3000;
    double dlt_t=0.2;//should be <=0.2
    double lmda=0.02;
    auto out = TSV_Inpaint(in,msk,it,dlt_t,lmda);

    auto outImg = img_rgb_to_QImage(out);

    outImg.save(argv[3], "PNG");

    img_rgb_destruct(in);
    img_rgb_destruct(msk);
    img_rgb_destruct(out);

    return 0;
}
