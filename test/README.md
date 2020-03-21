output is a 4x1 vector of integers. The model is trained to detect 4 different modulation methods. We apply the softmax function to the output vector to choose between 1 of 4 modulation methods: OOK (0),4ASK  (1), 8ASK (2), BPSK (3). The softmax is the index where the maximum value occurs in an array. 
We check the accuracy of the output against a validation set for different SNRs, and record the accuracy (100*correct choices / incorrect choices) in output.txt. 

DEPENDENCIES:
- tensorflow
- python3 
- debian machine for bash scripts

SETUP:
In linux, download tar.gz from here: deepsig.io to code/
```
cp tw_vgg10_hardware.c tw_vgg10.c
bash get_txt_files.sh
export MODEL_DIR=../models/vgg_twn_rfsoc_50k_64_d128
rm -rf build
python3 setup.py build
export PYTHONPATH=build/lib.linux-x86_64-3.6
python3 test_vggpy.py
```
alternatively, 
``` 
cp tw_vgg10_hardware.c tw_vgg10.c; bash run_all.sh 
```
output in output.txt

Output is printed to terminal in terms of accuracy relative to validation set. Validation set is a random shuffle of deepsig.io dataset, 1,000 samples long. each sample takes (1024,2) as input for the I and Q respectively.

sample output for a run of 100000 samples using hardware implementation (tw_vgg10_hardware.c) is given in output.txt
