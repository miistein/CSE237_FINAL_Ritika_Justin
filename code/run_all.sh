rm -rf I.txt Q.txt SNR.txt Y.txt
bash get_txt_files.sh
export MODEL_DIR=../models/vgg_twn_rfsoc_50k_64_d128
rm -rf build
python3 setup.py build
export PYTHONPATH=build/lib.linux-x86_64-3.6
python3 test_vggpy.py >> sample_output.txt
