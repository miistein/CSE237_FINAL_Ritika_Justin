# Take dataset as input, and shuffle. 
# Output:
# I.txt - each 1024 lines is an input array (real)
# Q.txt - each 1024 lines is an input array (imag)
# SNR.txt - repeat every 1024 lines the corresponding SNR
# y.txt - each 24 lines is the output array
#! /usr/bin/python3

# change if want more examples in the dataset, also need to change in test_vggpy.py
num_examples = 100000

import h5py
import sys
import numpy as np
import tensorflow as tf
import random
import argparse
import os

def get_example( x, y, snr, rcrd_prefix, rcrd_suffix ):
    label = int( np.argmax( y ) ).to_bytes( 1, byteorder='big')
    signal = np.reshape( np.transpose( x ), [ 2048 ] ) # flatten the signal to 1024xI followed by 1024xQ
    ftrs = {
        "signal" : tf.train.Feature( float_list = tf.train.FloatList(value = signal ) ),
        "label" : tf.train.Feature( bytes_list = tf.train.BytesList(value = [ label ] ) ),
        "snr" : tf.train.Feature( int64_list = tf.train.Int64List(value = [ snr ] ) )
    }
    example = tf.train.Example(features=tf.train.Features(feature=ftrs))
    return example.SerializeToString()

def make_wrt( snr, rcrd_prefix, rcrd_suffix ):
    return tf.python_io.TFRecordWriter( rcrd_prefix + str( snr ) + rcrd_suffix )

def add_to_rcrd( ex, wrts, snr, rcrd_prefix, rcrd_suffix ):
    if snr not in wrts:
        wrts[snr] = make_wrt( snr, rcrd_prefix, rcrd_suffix )
    wrt = wrts[ snr ]
    wrt.write( ex )
    return wrts

def partition_dataset():
    ary = np.array( ( [ True ] * 3686 ) + ( [ False ] * 410 ) )
    np.random.shuffle( ary )
    return ary

def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument( "--dataset_file", type = str, required = True,
                         help="The filename of the dataset")
    parser.add_argument( "--rcrd_prefix", type = str, default = "modulation_classification_test_snr_",
                         help="The filename prefix to use on the output")
    parser.add_argument( "--rcrd_suffix", type = str, default = ".rcrd",
                         help="The filename suffix to use on the output")
    return parser.parse_args()

if __name__ == "__main__":
    args = get_args()
    f = h5py.File( args.dataset_file, "r" )
    dirname = os.path.dirname( args.dataset_file )
    train_ex = []
    partition = partition_dataset()
    p_idx = 0
    test_wrts = {}
    prefix = dirname + "/" + args.rcrd_prefix
    i = 0
    examples = []
    lower , upper = 0 , num_examples
    for x, y, snr in zip( f["X"], f["Y"], f["Z"] ):
        if (i>=lower) and (len(x.tolist())==1024):
            ex = [x.astype('float'),y.astype('float'),snr.astype('float')]
            examples.append([ex])
        i+=1
        if(i==num_examples):
            break
    output = np.array(examples)
    np.random.shuffle( output )
    with open("I.txt",'w') as f, open("Q.txt","w") as f2, open("Y.txt","w") as f3, open("SNR.txt","w") as f4:
        # has 4096, line contains x,y,snr. x is (1024,2) y is 24
        for i in range(upper-lower):
            line = output[i][0]
            for j in range(1024):
                f.write(str(line[0][j][0]) + '\n')
                f2.write(str(line[0][j][1]) + '\n')
            
            f4.write(str(line[2][0]) + '\n')

            for k  in range(24):
                f3.write(str(line[1][k]) + '\n')
    print("finished writing text files")
