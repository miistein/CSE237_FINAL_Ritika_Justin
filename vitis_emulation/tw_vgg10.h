
#ifndef __TW_VGG10_H__
#define __TW_VGG10_H__
#define IMG_LEN 1024
#define IMG_FILT 2

extern "C" {
void compute_network( const short * img_r, short *out_r, int prec);
}
void allocate_network( int prec );
#endif
