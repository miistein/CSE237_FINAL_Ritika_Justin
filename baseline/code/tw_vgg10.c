#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tw_vgg10.h"

#include "conv1.h"
#include "conv2.h"
#include "conv3.h"
#include "conv4.h"
#include "conv5.h"
#include "conv6.h"
#include "conv7.h"
#include "bn1_a_b.h"
#include "bn2_a_b.h"
#include "bn3_a_b.h"
#include "bn4_a_b.h"
#include "bn5_a_b.h"
#include "bn6_a_b.h"
#include "bn7_a_b.h"
#include "dense1.h"
#include "bnd1_a_b.h"
#include "dense2.h"
#include "bnd2_a_b.h"
#include "vgg_dense_3.h"

#define KSIZE 3

// a struct to hold the network info
struct network_vars
{
  short dense3_vars[VGG_DENSE_3_LEN*VGG_DENSE_3_FILT];
  short lyr_w[7][192];
  short lyr_c[7][1024 * 64];
  short lyr_mp[7][1024 * 64];
  short d[3][128];
  int filts[8];
  int prec;
} n;

 void  convert_float( const float img[], short * img_out, int scale, int len, int filts) {
   for (int i = 0; i < len; i++ ) {
     for (int j = 0; j < filts; j++ ) {
    	 img_out[i*filts + j] = (short) ( img[i*filts + j] * scale );
     }
   }
}

void window_data_1d_1(const short img[IMG_LEN * IMG_FILT], short *out, int idx, int img_len, int no_filt)
{
  for (int i = -1; i < KSIZE - 1; i++)
  {
    for (int j = 0; j < no_filt; j++)
    {
      if (idx + i < 0 || idx + i >= img_len)
        out[(i + 1) * no_filt + j] = 0;
      else
        out[(i + 1) * no_filt + j] = img[(idx + i) * no_filt + j];
    }
  }
}

void window_data_1d_2(const short img[1024 * 64], short *out, int idx, int img_len, int no_filt)
{
  for (int i = -1; i < KSIZE - 1; i++)
  {
    for (int j = 0; j < no_filt; j++)
    {
      if (idx + i < 0 || idx + i >= img_len)
        out[(i + 1) * no_filt + j] = 0;
      else
        out[(i + 1) * no_filt + j] = img[(idx + i) * no_filt + j];
    }
  }
}


void compute_conv_layer_1(short out[1024 * 64], const short img[IMG_LEN * IMG_FILT], int img_len, int lyr_i)
{
  for (int idx = 0; idx < img_len; idx++)
  {
    // window
    window_data_1d_1(img, n.lyr_w[lyr_i], idx, img_len, n.filts[lyr_i]);
    // conv
    conv1(n.lyr_w[lyr_i], &(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
    // bn
    bn1_a_b(&(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
  }

  // maxpool
  for (int i = 0; i < img_len / 2; i++)
  {
    for (int j = 0; j < n.filts[lyr_i + 1]; j++)
    {
      if (n.lyr_c[lyr_i][2 * i * n.filts[lyr_i + 1] + j] > n.lyr_c[lyr_i][(2 * i + 1) * n.filts[lyr_i + 1] + j])
        out[i * n.filts[lyr_i + 1] + j] = n.lyr_c[lyr_i][2 * i * n.filts[lyr_i + 1] + j];
      else
        out[i * n.filts[lyr_i + 1] + j] = n.lyr_c[lyr_i][(2 * i + 1) * n.filts[lyr_i + 1] + j];
    }
  }
}

void compute_conv_layer_2(short out[1024 * 64], const short img[1024 * 64], int img_len, int lyr_i)
{
  for (int idx = 0; idx < img_len; idx++)
  {
	#pragma HLS loop_tripcount min=16 max=512
    // window
    window_data_1d_2(img, n.lyr_w[lyr_i], idx, img_len, n.filts[lyr_i]);
    // conv
    // bn
    switch (lyr_i)
    {
    case 1:
      conv2(n.lyr_w[lyr_i], &(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      bn2_a_b(&(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      break;
    case 2:
      conv3(n.lyr_w[lyr_i], &(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      bn3_a_b(&(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      break;
    case 3:
      conv4(n.lyr_w[lyr_i], &(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      bn4_a_b(&(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      break;
    case 4:
      conv5(n.lyr_w[lyr_i], &(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      bn5_a_b(&(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      break;
    case 5:
      conv6(n.lyr_w[lyr_i], &(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      bn6_a_b(&(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      break;
    case 6:
      conv7(n.lyr_w[lyr_i], &(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      bn7_a_b(&(n.lyr_c[lyr_i][idx * n.filts[lyr_i + 1]]));
      break;
    default:
    	break;
    }
  }
  // mp
  // maxpool
  for (int i = 0; i < img_len / 2; i++)
  {
    for (int j = 0; j < n.filts[lyr_i + 1]; j++)
    {
      if (n.lyr_c[lyr_i][2 * i * n.filts[lyr_i + 1] + j] > n.lyr_c[lyr_i][(2 * i + 1) * n.filts[lyr_i + 1] + j])
        out[i * n.filts[lyr_i + 1] + j] = n.lyr_c[lyr_i][2 * i * n.filts[lyr_i + 1] + j];
      else
        out[i * n.filts[lyr_i + 1] + j] = n.lyr_c[lyr_i][(2 * i + 1) * n.filts[lyr_i + 1] + j];
    }
  }
}

void compute_dense_layer_1(short img[512], int i)
{
  dense1(img, n.d[i]);
  bnd1_a_b(n.d[i]);
}

void compute_dense_layer_2(short img[128], int i)
{
  dense2(img, n.d[i]);
  bnd2_a_b(n.d[i]);
}

void allocate_network(int prec)
{
	#pragma HLS INTERFACE s_axilite port=return bundle=allocate
	#pragma HLS INTERFACE s_axilite port=prec bundle=allocate

  int img_len = IMG_LEN;

  n.prec = prec;
  convert_float(vgg_dense_3,n.dense3_vars,1<<prec,VGG_DENSE_3_LEN,VGG_DENSE_3_FILT);
  n.filts[0] = IMG_FILT;
  n.filts[1] = CONV1_OUT;
  n.filts[2] = CONV2_OUT;
  n.filts[3] = CONV3_OUT;
  n.filts[4] = CONV4_OUT;
  n.filts[5] = CONV5_OUT;
  n.filts[6] = CONV6_OUT;
  n.filts[7] = CONV7_OUT;

  no_classes = VGG_DENSE_3_FILT;
};

void compute_network(const short *img, short *out)
{
  #pragma HLS INTERFACE s_axilite port=return bundle=compute
  #pragma HLS INTERFACE m_axi depth=2048 port=img offset=slave bundle=input
  #pragma HLS INTERFACE m_axi depth=4 port=out offset=slave bundle=output
  #pragma HLS INTERFACE s_axilite port=out
  #pragma HLS INTERFACE s_axilite port=img

  int img_len = IMG_LEN;
  compute_conv_layer_1(n.lyr_mp[0], img, img_len, 0);
  for (int k = 1; k < 7; k++)
  {
    img_len /= 2;
    compute_conv_layer_2(n.lyr_mp[k], n.lyr_mp[k - 1], img_len, k);
  }

  compute_dense_layer_1(n.lyr_mp[6], 0);
  compute_dense_layer_2(n.d[0], 1);

  for (int i = 0; i < VGG_DENSE_3_FILT; i++)
  {
    int tmp_sum = 0;
    for (int j = 0; j < VGG_DENSE_3_LEN; j++)
      tmp_sum += n.dense3_vars[j * VGG_DENSE_3_FILT + i] * n.d[1][j];

    n.d[2][i] = (short)(tmp_sum >> n.prec);
  }
  for(int m=0; m<VGG_DENSE_3_FILT; m++)
	  out[m] = n.d[2][m];
}
