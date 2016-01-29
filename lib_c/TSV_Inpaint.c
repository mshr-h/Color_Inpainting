#include "include/image.h"

struct img_rgb_t *TSV_Inpaint(struct img_rgb_t *in_rgb,struct img_rgb_t *msk_rgb,
                              int it,double dlt_t,double lmda)
{
    int w,h,i;
    int wt,ht;

    struct map_t *n1,*n2;

    struct map_rgb_t *in;
    struct map_rgb_t *out;
    struct map_rgb_t *msk;
    struct map_rgb_t *Fxd,*Fyd;
    struct map_rgb_t *Bx,*By;
    struct img_rgb_t *out_rgb;

    wt=in_rgb->wt;
    ht=in_rgb->ht;

    n1=map_create(wt,ht,0.0);
    n2=map_create(wt,ht,0.0);
    out=map_rgb_create(wt,ht,0.0);

    in=img_to_map_rgb(in_rgb);
    msk=img_to_map_rgb(msk_rgb);

    Fxd=map_rgb_create(in->wt,in->ht,0.0);
    Fyd=map_rgb_create(in->wt,in->ht,0.0);
    Bx=map_rgb_create(in->wt,in->ht,0.0);
    By=map_rgb_create(in->wt,in->ht,0.0);

    //compute gradients
    for(h=1;h<ht-1;h++){
        for(w=1;w<wt-1;w++){
            n1->data[h][w]=in->r[h][w+1]-in->r[h][w];
            n2->data[h][w]=in->r[h+1][w]-in->r[h][w];
        }
    }

    //init
    for(h=0;h<ht;h++){
        for(w=0;w<wt;w++){
            if(msk->r[h][w]!=0 || msk->g[h][w]!=0 || msk->b[h][w]!=0){
                in->r[h][w]=msk->r[h][w];
                in->g[h][w]=msk->g[h][w];
                in->b[h][w]=msk->b[h][w];
            }
        }
    }

    //iteration
    for(i=0;i<it;i++){
        printf("i=%d\n",i);
        fflush(stdout);

        //compute gradients
        for(h=1;h<Fxd->ht-1;h++){
            for(w=1;w<Fxd->wt-1;w++){
                Fxd->r[h][w]=in->r[h][w+1]-in->r[h][w];
                Fxd->g[h][w]=in->g[h][w+1]-in->g[h][w];
                Fxd->b[h][w]=in->b[h][w+1]-in->b[h][w];

                Fyd->r[h][w]=in->r[h+1][w]-in->r[h][w];
                Fyd->g[h][w]=in->g[h+1][w]-in->g[h][w];
                Fyd->b[h][w]=in->b[h+1][w]-in->b[h][w];
            }
        }

        for(h=1;h<Bx->ht;h++){
            for(w=1;w<Bx->wt;w++){
                Bx->r[h][w]=(Fxd->r[h][w]-n1->data[h][w])-(Fxd->r[h][w-1]-n1->data[h][w-1]);
                Bx->g[h][w]=(Fxd->g[h][w]-n1->data[h][w])-(Fxd->g[h][w-1]-n1->data[h][w-1]);
                Bx->b[h][w]=(Fxd->b[h][w]-n1->data[h][w])-(Fxd->b[h][w-1]-n1->data[h][w-1]);

                By->r[h][w]=(Fyd->r[h][w]-n2->data[h][w])-(Fyd->r[h-1][w]-n2->data[h-1][w]);
                By->g[h][w]=(Fyd->g[h][w]-n2->data[h][w])-(Fyd->g[h-1][w]-n2->data[h-1][w]);
                By->b[h][w]=(Fyd->b[h][w]-n2->data[h][w])-(Fyd->b[h-1][w]-n2->data[h-1][w]);
            }
        }

        //update
        for(h=0;h<out->ht;h++){
            for(w=0;w<out->wt;w++){
                if((msk->r[h][w]==0)&&(msk->g[h][w]==0)&&(msk->b[h][w]==0)){
                    out->r[h][w]=in->r[h][w]+dlt_t*(Bx->r[h][w]+By->r[h][w]);
                    out->g[h][w]=in->g[h][w]+dlt_t*(Bx->g[h][w]+By->g[h][w]);
                    out->b[h][w]=in->b[h][w]+dlt_t*(Bx->b[h][w]+By->b[h][w]);
                }else{
                    out->r[h][w]=in->r[h][w]+dlt_t*(Bx->r[h][w]+By->r[h][w])+lmda*(msk->r[h][w]-in->r[h][w]);
                    out->g[h][w]=in->g[h][w]+dlt_t*(Bx->g[h][w]+By->g[h][w])+lmda*(msk->g[h][w]-in->g[h][w]);
                    out->b[h][w]=in->b[h][w]+dlt_t*(Bx->b[h][w]+By->b[h][w])+lmda*(msk->b[h][w]-in->b[h][w]);
                }
            }
        }

        for(h=0;h<out->ht;h++){
            for(w=0;w<out->wt;w++){
                out->r[h][w]=(out->r[h][w]<0)?0.0:
                             (out->r[h][w]>1)?1.0:
                                              out->r[h][w];
                out->g[h][w]=(out->g[h][w]<0)?0.0:
                             (out->g[h][w]>1)?1.0:
                                              out->g[h][w];
                out->b[h][w]=(out->b[h][w]<0)?0.0:
                             (out->b[h][w]>1)?1.0:
                                              out->b[h][w];
            }
        }

        for(h=0;h<ht;h++){
            for(w=0;w<wt;w++){
                in->r[h][w]=out->r[h][w];
                in->g[h][w]=out->g[h][w];
                in->b[h][w]=out->b[h][w];
            }
        }

    }//for(i=0;.....)

    out_rgb=map_to_img_rgb(out);
    map_destruct(n1);
    map_destruct(n2);
    map_rgb_destruct(msk);
    map_rgb_destruct(in);
    map_rgb_destruct(out);
    map_rgb_destruct(Fxd);
    map_rgb_destruct(Fyd);
    map_rgb_destruct(Bx);
    map_rgb_destruct(By);

    return out_rgb;
}
