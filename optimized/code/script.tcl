############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Final2
set_top compute_network
add_files ../../../../Desktop/CSE237C/all_files2/bn1_a_b.c
add_files ../../../../Desktop/CSE237C/all_files2/bn1_a_b.h
add_files ../../../../Desktop/CSE237C/all_files2/bn2_a_b.c
add_files ../../../../Desktop/CSE237C/all_files2/bn2_a_b.h
add_files ../../../../Desktop/CSE237C/all_files2/bn3_a_b.c
add_files ../../../../Desktop/CSE237C/all_files2/bn3_a_b.h
add_files ../../../../Desktop/CSE237C/all_files2/bn4_a_b.c
add_files ../../../../Desktop/CSE237C/all_files2/bn4_a_b.h
add_files ../../../../Desktop/CSE237C/all_files2/bn5_a_b.c
add_files ../../../../Desktop/CSE237C/all_files2/bn5_a_b.h
add_files ../../../../Desktop/CSE237C/all_files2/bn6_a_b.c
add_files ../../../../Desktop/CSE237C/all_files2/bn6_a_b.h
add_files ../../../../Desktop/CSE237C/all_files2/bn7_a_b.c
add_files ../../../../Desktop/CSE237C/all_files2/bn7_a_b.h
add_files ../../../../Desktop/CSE237C/all_files2/bnd1_a_b.c
add_files ../../../../Desktop/CSE237C/all_files2/bnd1_a_b.h
add_files ../../../../Desktop/CSE237C/all_files2/bnd2_a_b.c
add_files ../../../../Desktop/CSE237C/all_files2/bnd2_a_b.h
add_files ../../../../Desktop/CSE237C/all_files2/conv1.c
add_files ../../../../Desktop/CSE237C/all_files2/conv1.h
add_files ../../../../Desktop/CSE237C/all_files2/conv2.c
add_files ../../../../Desktop/CSE237C/all_files2/conv2.h
add_files ../../../../Desktop/CSE237C/all_files2/conv3.c
add_files ../../../../Desktop/CSE237C/all_files2/conv3.h
add_files ../../../../Desktop/CSE237C/all_files2/conv4.c
add_files ../../../../Desktop/CSE237C/all_files2/conv4.h
add_files ../../../../Desktop/CSE237C/all_files2/conv5.c
add_files ../../../../Desktop/CSE237C/all_files2/conv5.h
add_files ../../../../Desktop/CSE237C/all_files2/conv6.c
add_files ../../../../Desktop/CSE237C/all_files2/conv6.h
add_files ../../../../Desktop/CSE237C/all_files2/conv7.c
add_files ../../../../Desktop/CSE237C/all_files2/conv7.h
add_files ../../../../Desktop/CSE237C/all_files2/dense1.c
add_files ../../../../Desktop/CSE237C/all_files2/dense1.h
add_files ../../../../Desktop/CSE237C/all_files2/dense2.c
add_files ../../../../Desktop/CSE237C/all_files2/dense2.h
add_files ../../../../Desktop/CSE237C/all_files2/tw_vgg10.c
add_files ../../../../Desktop/CSE237C/all_files2/tw_vgg10.h
add_files ../../../../Desktop/CSE237C/all_files2/vgg_dense_3.h
add_files -tb ../../../../Desktop/CSE237C/all_files2/pyvgg.c
open_solution "solution1"
set_part {xczu28dr-ffvg1517-2-e}
create_clock -period 10 -name default
#source "./Final2/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
