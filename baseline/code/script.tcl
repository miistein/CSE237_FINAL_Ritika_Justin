############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Radio_Mod
set_top compute_network
add_files ../../../../Desktop/CSE237C/all_files/vgg_dense_3.h
add_files ../../../../Desktop/CSE237C/all_files/tw_vgg10.h
add_files ../../../../Desktop/CSE237C/all_files/tw_vgg10.c
add_files ../../../../Desktop/CSE237C/all_files/dense2.h
add_files ../../../../Desktop/CSE237C/all_files/dense2.c
add_files ../../../../Desktop/CSE237C/all_files/dense1.h
add_files ../../../../Desktop/CSE237C/all_files/dense1.c
add_files ../../../../Desktop/CSE237C/all_files/conv7.h
add_files ../../../../Desktop/CSE237C/all_files/conv7.c
add_files ../../../../Desktop/CSE237C/all_files/conv6.h
add_files ../../../../Desktop/CSE237C/all_files/conv6.c
add_files ../../../../Desktop/CSE237C/all_files/conv5.h
add_files ../../../../Desktop/CSE237C/all_files/conv5.c
add_files ../../../../Desktop/CSE237C/all_files/conv4.h
add_files ../../../../Desktop/CSE237C/all_files/conv4.c
add_files ../../../../Desktop/CSE237C/all_files/conv3.h
add_files ../../../../Desktop/CSE237C/all_files/conv3.c
add_files ../../../../Desktop/CSE237C/all_files/conv2.h
add_files ../../../../Desktop/CSE237C/all_files/conv2.c
add_files ../../../../Desktop/CSE237C/all_files/conv1.h
add_files ../../../../Desktop/CSE237C/all_files/conv1.c
add_files ../../../../Desktop/CSE237C/all_files/bnd2_a_b.h
add_files ../../../../Desktop/CSE237C/all_files/bnd2_a_b.c
add_files ../../../../Desktop/CSE237C/all_files/bnd1_a_b.h
add_files ../../../../Desktop/CSE237C/all_files/bnd1_a_b.c
add_files ../../../../Desktop/CSE237C/all_files/bn7_a_b.h
add_files ../../../../Desktop/CSE237C/all_files/bn7_a_b.c
add_files ../../../../Desktop/CSE237C/all_files/bn6_a_b.h
add_files ../../../../Desktop/CSE237C/all_files/bn6_a_b.c
add_files ../../../../Desktop/CSE237C/all_files/bn5_a_b.h
add_files ../../../../Desktop/CSE237C/all_files/bn5_a_b.c
add_files ../../../../Desktop/CSE237C/all_files/bn4_a_b.h
add_files ../../../../Desktop/CSE237C/all_files/bn4_a_b.c
add_files ../../../../Desktop/CSE237C/all_files/bn3_a_b.h
add_files ../../../../Desktop/CSE237C/all_files/bn3_a_b.c
add_files ../../../../Desktop/CSE237C/all_files/bn2_a_b.h
add_files ../../../../Desktop/CSE237C/all_files/bn2_a_b.c
add_files ../../../../Desktop/CSE237C/all_files/bn1_a_b.h
add_files ../../../../Desktop/CSE237C/all_files/bn1_a_b.c
add_files -tb ../../../../Desktop/CSE237C/all_files/pyvgg.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xczu28dr-ffvg1517-2-e}
create_clock -period 10 -name default
#source "./Radio_Mod/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
