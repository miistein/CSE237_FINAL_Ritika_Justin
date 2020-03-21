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

void  convert_float( const float img[], short * img_out, int scale, int len, int filts) {
	for (int i = 0; i < len; i++ ) {
		for (int j = 0; j < filts; j++ ) {
			#pragma HLS pipeline
			img_out[i*filts + j] = (short) ( img[i*filts + j] * scale );
		}
	}
}

void window_data_1d_1(const short img[IMG_LEN * IMG_FILT], short *out, int idx, int img_len, int no_filt)
{
	for (int i = -1; i < KSIZE - 1; i++) {
		for (int j = 0; j < no_filt; j++) {

			#pragma HLS pipeline

			if (idx + i < 0 || idx + i >= img_len)
				out[(i + 1) * no_filt + j] = 0;
			else
				out[(i + 1) * no_filt + j] = img[(idx + i) * no_filt + j];
		}
	}
}

void window_data_1d_2(const short img[1024 * 64], short *out, int idx, int img_len, int no_filt)
{
	for (int i = -1; i < KSIZE - 1; i++) {
		for (int j = 0; j < no_filt; j++) {

			#pragma HLS pipeline

			if (idx + i < 0 || idx + i >= img_len)
				out[(i + 1) * no_filt + j] = 0;
			else
				out[(i + 1) * no_filt + j] = img[(idx + i) * no_filt + j];
		}
	}
}

void maxpool_1d_2( const short *img, short *out, int len, int filts ) {
	for (int i = 0; i < len/2; i++ ) {
		for (int j = 0; j < filts; j++ ) {
			#pragma HLS pipeline
			if ( img[2*i*filts + j] > img[(2*i + 1)*filts + j] )
				out[i*filts + j] = img[2*i*filts + j];
			else
				out[i*filts + j] = img[(2*i + 1)*filts + j];
		}
	}
}

void compute_conv_layer_1(short out[1024 * 64], const short img[IMG_LEN * IMG_FILT], int img_len, short lyr_w[6], short lyr_c[1024 * 64])
{
	for (int idx = 0; idx < img_len; idx++) {
		#pragma HLS pipeline
		// window
		window_data_1d_1(img, lyr_w, idx, img_len, 2);
	    // conv
	    conv1(lyr_w, &(lyr_c[idx * 64]));
	    // bn
	    bn1_a_b(&(lyr_c[idx * 64]));
	}

	// maxpool
	maxpool_1d_2( lyr_c, out, img_len, 64);
}

void compute_conv_layer_2(short out[512 * 64], const short img[1024 * 64], int img_len, short lyr_w[192], short lyr_c[512 * 64])
{
	for (int idx = 0; idx < img_len; idx++) {
		#pragma HLS pipeline
		// window
		window_data_1d_2(img, lyr_w, idx, img_len, 64);
		// conv
		conv2(lyr_w, &(lyr_c[idx * 64]));
		// bn
		bn2_a_b(&(lyr_c[idx * 64]));
	}

	// maxpool
	maxpool_1d_2( lyr_c, out, img_len, 64 );
}

void compute_conv_layer_3(short out[256 * 64], const short img[512 * 64], int img_len, short lyr_w[192], short lyr_c[256 * 64])
{
	for (int idx = 0; idx < img_len; idx++) {
		#pragma HLS pipeline
		// window
		window_data_1d_2(img, lyr_w, idx, img_len, 64);
		// conv
		conv3(lyr_w, &(lyr_c[idx * 64]));
		// bn
		bn3_a_b(&(lyr_c[idx * 64]));
	}

	// maxpool
	maxpool_1d_2( lyr_c, out, img_len, 64 );
}

void compute_conv_layer_4(short out[128 * 64], const short img[256 * 64], int img_len, short lyr_w[192], short lyr_c[128 * 64])
{
	for (int idx = 0; idx < img_len; idx++) {
		#pragma HLS pipeline
		// window
		window_data_1d_2(img, lyr_w, idx, img_len, 64);
		// conv
		conv4(lyr_w, &(lyr_c[idx * 64]));
		// bn
		bn4_a_b(&(lyr_c[idx * 64]));
	}

	// maxpool
	maxpool_1d_2( lyr_c, out, img_len, 64 );
}

void compute_conv_layer_5(short out[64 * 64], const short img[128 * 64], int img_len, short lyr_w[192], short lyr_c[64 * 64])
{

	for (int idx = 0; idx < img_len; idx++)
	{
		#pragma HLS pipeline
		// window
		window_data_1d_2(img, lyr_w, idx, img_len, 64);
		// conv
		conv5(lyr_w, &(lyr_c[idx * 64]));
		// bn
		bn5_a_b(&(lyr_c[idx * 64]));
	}
	// maxpool
	maxpool_1d_2( lyr_c, out, img_len, 64 );
}

void compute_conv_layer_6(short out[32 * 64], const short img[1024 * 64], int img_len, short lyr_w[192], short lyr_c[32 * 64])
{
	for (int idx = 0; idx < img_len; idx++)
	{
		#pragma HLS pipeline
		// window
		window_data_1d_2(img, lyr_w, idx, img_len, 64);
		// conv
		conv6(lyr_w, &(lyr_c[idx * 64]));
		// bn
		bn6_a_b(&(lyr_c[idx * 64]));
	}
	// maxpool
	maxpool_1d_2( lyr_c, out, img_len, 64 );
}

void compute_conv_layer_7(short out[16 * 64], const short img[1024 * 64], int img_len, short lyr_w[192], short lyr_c[16 * 64])
{
	for (int idx = 0; idx < img_len; idx++)
	{
		#pragma HLS pipeline
		// window
		window_data_1d_2(img, lyr_w, idx, img_len, 64);
		// conv
		conv7(lyr_w, &(lyr_c[idx * 64]));
		// bn
		bn7_a_b(&(lyr_c[idx * 64]));
	}

	// maxpool
	maxpool_1d_2(lyr_c, out, img_len, 64);
}

void compute_dense_layer_1(short img[512], short d[128])
{
	dense1(img, d);
	bnd1_a_b(d);
}

void compute_dense_layer_2(short img[128], short d[128])
{
	dense2(img, d);
	bnd2_a_b(d);
}

void compute_d3(short d[VGG_DENSE_3_LEN], short out[VGG_DENSE_3_FILT], short dense3_vars[VGG_DENSE_3_LEN*VGG_DENSE_3_FILT]){

	for (int i = 0; i < VGG_DENSE_3_FILT; i++)
	{
		int tmp_sum = 0;
		for (int j = 0; j < VGG_DENSE_3_LEN; j++) {
			#pragma HLS pipeline
			tmp_sum += dense3_vars[j * VGG_DENSE_3_FILT + i] * d[j];
		}
		out[i] = (short)(tmp_sum >> PREC);
	}
}


void compute_network(const short *img, short *out)
{
	#pragma HLS INTERFACE s_axilite port=return bundle=compute
	#pragma HLS INTERFACE m_axi depth=2048 port=img offset=slave bundle=input
	#pragma HLS INTERFACE m_axi depth=4 port=out offset=slave bundle=output
	#pragma HLS INTERFACE s_axilite port=out
	#pragma HLS INTERFACE s_axilite port=img

	short lyr_mp_0[1024 * 64];
	short lyr_mp_1[512 * 64];
	short lyr_mp_2[256 * 64];
	short lyr_mp_3[128 * 64];
	short lyr_mp_4[64 * 64];
	short lyr_mp_5[32 * 64];
	short lyr_mp_6[16 * 64];
	short d_0[128];
	short d_1[128];
	short lyr_w_0[6];
	short lyr_w_1[192];
	short lyr_w_2[192];
	short lyr_w_3[192];
	short lyr_w_4[192];
	short lyr_w_5[192];
	short lyr_w_6[192];
	short lyr_c_0[1024 * 64];
	short lyr_c_1[512 * 64];
	short lyr_c_2[256 * 64];
	short lyr_c_3[128 * 64];
	short lyr_c_4[64 * 64];
	short lyr_c_5[32 * 64];
	short lyr_c_6[16 * 64];
	short dense3_vars[VGG_DENSE_3_LEN*VGG_DENSE_3_FILT];

	#pragma HLS dataflow
	#pragma HLS array_partition variable=lyr_mp_0 block factor=2
	#pragma HLS array_partition variable=lyr_mp_1 block factor=2
	#pragma HLS array_partition variable=lyr_mp_2 block factor=2
	#pragma HLS array_partition variable=lyr_mp_3 block factor=2
	#pragma HLS array_partition variable=lyr_mp_4 block factor=2
	#pragma HLS array_partition variable=lyr_mp_5 block factor=2
	#pragma HLS array_partition variable=lyr_mp_6 block factor=2

	#pragma HLS array_partition variable=d_0 block factor=2
	#pragma HLS array_partition variable=d_1 block factor=2

	#pragma HLS array_partition variable=lyr_w_0 block factor=2
	#pragma HLS array_partition variable=lyr_w_1 block factor=2
	#pragma HLS array_partition variable=lyr_w_2 block factor=2
	#pragma HLS array_partition variable=lyr_w_3 block factor=2
	#pragma HLS array_partition variable=lyr_w_4 block factor=2
	#pragma HLS array_partition variable=lyr_w_5 block factor=2
	#pragma HLS array_partition variable=lyr_w_6 block factor=2

	#pragma HLS array_partition variable=lyr_c_0 block factor=2
	#pragma HLS array_partition variable=lyr_c_1 block factor=2
	#pragma HLS array_partition variable=lyr_c_2 block factor=2
	#pragma HLS array_partition variable=lyr_c_3 block factor=2
	#pragma HLS array_partition variable=lyr_c_4 block factor=2
	#pragma HLS array_partition variable=lyr_c_5 block factor=2
	#pragma HLS array_partition variable=lyr_c_6 block factor=2

	#pragma HLS array_partition variable=dense3_vars block factor=2 dim=1

	compute_conv_layer_1(lyr_mp_0, img, IMG_LEN, lyr_w_0, lyr_c_0);
	compute_conv_layer_2(lyr_mp_1, lyr_mp_0, IMG_LEN/2, lyr_w_1, lyr_c_1);
	compute_conv_layer_3(lyr_mp_2, lyr_mp_1, IMG_LEN/4, lyr_w_2, lyr_c_2);
	compute_conv_layer_4(lyr_mp_3, lyr_mp_2, IMG_LEN/8, lyr_w_3, lyr_c_3);
	compute_conv_layer_5(lyr_mp_4, lyr_mp_3, IMG_LEN/16, lyr_w_4, lyr_c_4);
	compute_conv_layer_6(lyr_mp_5, lyr_mp_4, IMG_LEN/32, lyr_w_5, lyr_c_5);
	compute_conv_layer_7(lyr_mp_6, lyr_mp_5, IMG_LEN/64, lyr_w_6, lyr_c_6);

	compute_dense_layer_1(lyr_mp_6, d_0);
	compute_dense_layer_2(d_0, d_1);

	convert_float(vgg_dense_3, dense3_vars, 1<<PREC, VGG_DENSE_3_LEN, VGG_DENSE_3_FILT);

	compute_d3(d_1, out, dense3_vars);
}
