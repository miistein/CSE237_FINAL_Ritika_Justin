
#ifndef __TW_VGG10_H__
#define __TW_VGG10_H__
#define IMG_LEN 1024
#define IMG_FILT 2

unsigned int no_classes;

void compute_network2( const short * img_r, short *out_r, int prec);
void allocate_network2( int prec );

#include <stdio.h>

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

#define KSIZE2 3

// a struct to hold the network info
short dense3_vars[VGG_DENSE_3_LEN * VGG_DENSE_3_FILT]; //128*4
short lyr_w[7][192];                                   // lyr_w[0]-> size 6, lyr_w[1-6] -> size 192
short lyr_c[7][1024 * 64];                             // lyr_c[0] -> 1024*64 , lyr_c[1] -> 512*64, lyr_c[2] -> 256*64 ...
short lyr_mp[7][1024 * 64];                            // lyr_mp[0] -> 1024*64 , lyr_mp[1] -> 512*64, lyr_mp[2] -> 256*64 ...
short d0[128];                                         //d[0-1] -> 128, d[2] -> 4
short d1[128];                                         //d[0-1] -> 128, d[2] -> 4
short d2[4];                                           //d[0-1] -> 128, d[2] -> 4

int filts[8];

short lyr_mp02[1024 * 64]; // lyr_mp[0] -> 1024*64 , lyr_mp[1] -> 512*64, lyr_mp[2] -> 256*64 ...
short lyr_mp12[512 * 64];  // lyr_mp[0] -> 1024*64 , lyr_mp[1] -> 512*64, lyr_mp[2] -> 256*64 ...
short lyr_mp22[256 * 64];  // lyr_mp[0] -> 1024*64 , lyr_mp[1] -> 512*64, lyr_mp[2] -> 256*64 ...
short lyr_mp32[128 * 64];  // lyr_mp[0] -> 1024*64 , lyr_mp[1] -> 512*64, lyr_mp[2] -> 256*64 ...
short lyr_mp42[64 * 64];   // lyr_mp[0] -> 1024*64 , lyr_mp[1] -> 512*64, lyr_mp[2] -> 256*64 ...
short lyr_mp52[32 * 64];   // lyr_mp[0] -> 1024*64 , lyr_mp[1] -> 512*64, lyr_mp[2] -> 256*64 ...
short lyr_mp62[16 * 64];   // lyr_mp[0] -> 1024*64 , lyr_mp[1] -> 512*64, lyr_mp[2] -> 256*64 ...

void convert_float2(const float img_r[], short *img_r_out_r, int scale, int len, int filts)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < filts; j++)
        {
            img_r_out_r[i * filts + j] = (short)(img_r[i * filts + j] * scale);
        }
    }
}

void window_data_1d_12(const short img_r[IMG_LEN * IMG_FILT], short *out_r, int idx, int img_r_len, int no_filt)
{
    for (int i = -1; i < KSIZE2 - 1; i++)
    {
        for (int j = 0; j < no_filt; j++)
        {
            if (idx + i < 0 || idx + i >= img_r_len)
                out_r[(i + 1) * no_filt + j] = 0;
            else
                out_r[(i + 1) * no_filt + j] = img_r[(idx + i) * no_filt + j];
        }
    }
}

void window_data_1d_22(const short img_r[1024 * 64], short *out_r, int idx, int img_r_len, int no_filt)
{
    for (int i = -1; i < KSIZE2 - 1; i++)
    {
        for (int j = 0; j < no_filt; j++)
        {
            if (idx + i < 0 || idx + i >= img_r_len)
                out_r[(i + 1) * no_filt + j] = 0;
            else
                out_r[(i + 1) * no_filt + j] = img_r[(idx + i) * no_filt + j];
        }
    }
}

void compute_conv_layer_12(short out_r[1024 * 64], const short img_r[IMG_LEN * IMG_FILT], int img_r_len, int lyr_i)
{
    for (int idx = 0; idx < img_r_len; idx++)
    {
        // window
        window_data_1d_12(img_r, lyr_w[lyr_i], idx, img_r_len, filts[lyr_i]);
        // conv
        conv1(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
        // bn
        bn1_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
    }

    // maxpool
    for (int i = 0; i < img_r_len / 2; i++)
    {
        for (int j = 0; j < filts[lyr_i + 1]; j++)
        {
            if (lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j] > lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j])
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j];
            else
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j];
        }
    }
}

void compute_conv_layer_2_12(short out_r[512 * 64], const short img_r[1024 * 64], int img_r_len, int lyr_i)
{
    for (int idx = 0; idx < img_r_len; idx++)
    {
#pragma HLS loop_tripcount min = 16 max = 512
        // window
        window_data_1d_22(img_r, lyr_w[lyr_i], idx, img_r_len, filts[lyr_i]);
        // conv
        // bn
        switch (lyr_i)
        {
        case 1:
            conv2(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn2_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 2:
            conv3(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn3_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 3:
            conv4(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn4_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 4:
            conv5(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn5_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 5:
            conv6(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn6_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 6:
            conv7(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn7_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        default:
            break;
        }
    }
    // mp
    // maxpool
    for (int i = 0; i < img_r_len / 2; i++)
    {
        for (int j = 0; j < filts[lyr_i + 1]; j++)
        {
            if (lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j] > lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j])
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j];
            else
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j];
        }
    }
}

void compute_conv_layer_2_22(short out_r[256 * 64], const short img_r[1024 * 64], int img_r_len, int lyr_i)
{
    for (int idx = 0; idx < img_r_len; idx++)
    {
#pragma HLS loop_tripcount min = 16 max = 512
        // window
        window_data_1d_22(img_r, lyr_w[lyr_i], idx, img_r_len, filts[lyr_i]);
        // conv
        // bn
        switch (lyr_i)
        {
        case 1:
            conv2(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn2_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 2:
            conv3(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn3_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 3:
            conv4(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn4_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 4:
            conv5(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn5_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 5:
            conv6(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn6_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 6:
            conv7(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn7_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        default:
            break;
        }
    }
    // mp
    // maxpool
    for (int i = 0; i < img_r_len / 2; i++)
    {
        for (int j = 0; j < filts[lyr_i + 1]; j++)
        {
            if (lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j] > lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j])
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j];
            else
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j];
        }
    }
}

void compute_conv_layer_2_32(short out_r[128 * 64], const short img_r[1024 * 64], int img_r_len, int lyr_i)
{
    for (int idx = 0; idx < img_r_len; idx++)
    {
#pragma HLS loop_tripcount min = 16 max = 512
        // window
        window_data_1d_22(img_r, lyr_w[lyr_i], idx, img_r_len, filts[lyr_i]);
        // conv
        // bn
        switch (lyr_i)
        {
        case 1:
            conv2(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn2_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 2:
            conv3(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn3_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 3:
            conv4(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn4_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 4:
            conv5(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn5_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 5:
            conv6(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn6_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 6:
            conv7(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn7_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        default:
            break;
        }
    }
    // mp
    // maxpool
    for (int i = 0; i < img_r_len / 2; i++)
    {
        for (int j = 0; j < filts[lyr_i + 1]; j++)
        {
            if (lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j] > lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j])
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j];
            else
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j];
        }
    }
}

void compute_conv_layer_2_42(short out_r[64 * 64], const short img_r[1024 * 64], int img_r_len, int lyr_i)
{
    for (int idx = 0; idx < img_r_len; idx++)
    {
#pragma HLS loop_tripcount min = 16 max = 512
        // window
        window_data_1d_22(img_r, lyr_w[lyr_i], idx, img_r_len, filts[lyr_i]);
        // conv
        // bn
        switch (lyr_i)
        {
        case 1:
            conv2(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn2_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 2:
            conv3(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn3_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 3:
            conv4(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn4_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 4:
            conv5(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn5_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 5:
            conv6(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn6_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 6:
            conv7(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn7_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        default:
            break;
        }
    }
    // mp
    // maxpool
    for (int i = 0; i < img_r_len / 2; i++)
    {
        for (int j = 0; j < filts[lyr_i + 1]; j++)
        {
            if (lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j] > lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j])
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j];
            else
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j];
        }
    }
}

void compute_conv_layer_2_52(short out_r[32 * 64], const short img_r[1024 * 64], int img_r_len, int lyr_i)
{
    for (int idx = 0; idx < img_r_len; idx++)
    {
#pragma HLS loop_tripcount min = 16 max = 512
        // window
        window_data_1d_22(img_r, lyr_w[lyr_i], idx, img_r_len, filts[lyr_i]);
        // conv
        // bn
        switch (lyr_i)
        {
        case 1:
            conv2(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn2_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 2:
            conv3(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn3_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 3:
            conv4(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn4_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 4:
            conv5(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn5_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 5:
            conv6(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn6_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 6:
            conv7(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn7_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        default:
            break;
        }
    }
    // mp
    // maxpool
    for (int i = 0; i < img_r_len / 2; i++)
    {
        for (int j = 0; j < filts[lyr_i + 1]; j++)
        {
            if (lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j] > lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j])
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j];
            else
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j];
        }
    }
}

void compute_conv_layer_2_62(short out_r[16 * 64], const short img_r[1024 * 64], int img_r_len, int lyr_i)
{
    for (int idx = 0; idx < img_r_len; idx++)
    {
#pragma HLS loop_tripcount min = 16 max = 512
        // window
        window_data_1d_22(img_r, lyr_w[lyr_i], idx, img_r_len, filts[lyr_i]);
        // conv
        // bn
        switch (lyr_i)
        {
        case 1:
            conv2(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn2_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 2:
            conv3(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn3_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 3:
            conv4(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn4_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 4:
            conv5(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn5_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 5:
            conv6(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn6_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        case 6:
            conv7(lyr_w[lyr_i], &(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            bn7_a_b(&(lyr_c[lyr_i][idx * filts[lyr_i + 1]]));
            break;
        default:
            break;
        }
    }
    // mp
    // maxpool
    for (int i = 0; i < img_r_len / 2; i++)
    {
        for (int j = 0; j < filts[lyr_i + 1]; j++)
        {
            if (lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j] > lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j])
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][2 * i * filts[lyr_i + 1] + j];
            else
                out_r[i * filts[lyr_i + 1] + j] = lyr_c[lyr_i][(2 * i + 1) * filts[lyr_i + 1] + j];
        }
    }
}

void compute_dense_layer_12(short img_r[16 * 64])
{
    dense1(img_r, d0);
    bnd1_a_b(d0);
}

void compute_dense_layer_22(short img_r[128])
{
    dense2(img_r, d1);
    bnd2_a_b(d1);
}

void allocate_network2(int prec)
{

    int img_r_len = IMG_LEN;

    convert_float2(vgg_dense_3, dense3_vars, 1 << prec, VGG_DENSE_3_LEN, VGG_DENSE_3_FILT);
    filts[0] = IMG_FILT;
    filts[1] = CONV1_OUT;
    filts[2] = CONV2_OUT;
    filts[3] = CONV3_OUT;
    filts[4] = CONV4_OUT;
    filts[5] = CONV5_OUT;
    filts[6] = CONV6_OUT;
    filts[7] = CONV7_OUT;

    //  no_classes = VGG_DENSE_3_FILT;
};

    void compute_network2(const short *img_r, short *out_r, int prec)
    {
#pragma HLS INTERFACE s_axilite port = return bundle = control
#pragma HLS INTERFACE m_axi depth = 2048 port = img_r offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi depth = 4 port = out_r offset = slave bundle = gmem
#pragma HLS INTERFACE s_axilite port = img_r bundle = control
#pragma HLS INTERFACE s_axilite port = out_r bundle = control
#pragma HLS INTERFACE s_axilite port = prec bundle = control

#pragma HLS array_partition cyclic variable = lyr_w factor = 2
#pragma HLS array_partition cyclic variable = lyr_c factor = 2
#pragma HLS array_partition cyclic variable = lyr_mp02 factor = 2
#pragma HLS array_partition cyclic variable = lyr_mp12 factor = 2
#pragma HLS array_partition cyclic variable = lyr_mp22 factor = 2
#pragma HLS array_partition cyclic variable = lyr_mp32 factor = 2
#pragma HLS array_partition cyclic variable = lyr_mp42 factor = 2
#pragma HLS array_partition cyclic variable = lyr_mp52 factor = 2
#pragma HLS array_partition cyclic variable = lyr_mp62 factor = 2

        allocate_network2(prec);
        int img_r_len = IMG_LEN;
        compute_conv_layer_12(lyr_mp02, img_r, 1024, 0);

        compute_conv_layer_2_12(lyr_mp12, lyr_mp02, 512, 1);
        compute_conv_layer_2_22(lyr_mp22, lyr_mp12, 256, 2);
        compute_conv_layer_2_32(lyr_mp32, lyr_mp22, 128, 3);
        compute_conv_layer_2_42(lyr_mp42, lyr_mp32, 64, 4);
        compute_conv_layer_2_52(lyr_mp52, lyr_mp42, 32, 5);
        compute_conv_layer_2_62(lyr_mp62, lyr_mp52, 16, 6);

        compute_dense_layer_12(lyr_mp62);
        compute_dense_layer_22(d0);

        for (int i = 0; i < VGG_DENSE_3_FILT; i++)
        {
            int tmp_sum = 0;
            for (int j = 0; j < VGG_DENSE_3_LEN; j++)
                tmp_sum += dense3_vars[j * VGG_DENSE_3_FILT + i] * d1[j];

            d2[i] = (short)(tmp_sum >> prec);
        }
        for (int m = 0; m < VGG_DENSE_3_FILT; m++)
            out_r[m] = d2[m];
    }
#endif
