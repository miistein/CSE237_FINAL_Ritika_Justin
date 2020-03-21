
#ifndef __TW_VGG10_H__
#define __TW_VGG10_H__
#define IMG_LEN 1024
#define IMG_FILT 2

unsigned int no_classes;

void compute_network( const short * img, short *out);
void allocate_network( int prec );
#endif
