## Our Progress on the Milestones:
1. Port the code to Vitis and write a testbench in Vitis to check functional correctness of the
code. It should be very close in accuracy to the software neural network but will vary
slightly due to variable precision and the optimizations we choose to take.
Deliverable: A synthesizable design that is tested, along with .bit/.hwh files. [x]

We have Vitis_emulation/compute_network.xilinx_u200_xdma_201830_2.xclbin, which can be used to run on linux in emulation and on the **u200_xdma_201830_2** board.
The Vitis_emulation/compute_network.xilinx_u200_xdma_201830_2.xo file is a kernel that can be compiled into any other Vitis project. This is easily portable to other boards, we chose this board because 
it was one of the few boards available in Vitis: https://www.xilinx.com/products/design-tools/Vitis/Vitis-platform.html. Vitis is a new platform and not so user friendly. We had to change the target device
so that we could move on with the project. It is possible to use the ZCU111 board as a target device in Vitis as we planned, but it is not officially supported yet by Xilinx so this is not an easy task.


2. Understand optimizations in Xilinx Vitis ( pragmas in Vivado HLS + OpenCL
optimizations) and use it to optimize the C code (already available) of real-time
automatic modulation classification. 
Deliverable: Optimized code, with a small outline of explored design space for use in the
documentation. [x]

See Initial Implementation with Vitis HLS and Optimizing the design in Vitis HLS in Report.pdf

3. Synthesize the code and port the code to the target board (RFSoC ZCU111). Write a
Jupyter python notebook to verify the synthesized code on the board.
Deliverable: A jupyter notebook demo, with the input as a modulated signal with error
and the output identifying that signal with a high degree of accuracy.
Target date: 03/17/2020

**not completed** since we used a different target board.

4. Finish up documentation that covers the pitfalls of porting to Vitis along with a high level
overview of any major adjustments we made to the code, the optimizations (and their
tradeoffs) we tried in Vitis, and a readable ipynb demo.
Deliverable: 2 README files in the github repo (one for Vitis code and another for
optimizations), well commented code , and a ipynb demo that demonstrates the results in
an easy to comprehend fashion. [x]

See Report.pdf. Setup.pdf reports the pit falls of Vitis as well, but it mainly focuses on how to get Vitis up and running.

Mapping Milestones to final project grade:

- Completing all milestones results in an A
- Completing milestones 1, 2, and 4 results in an A- [x]
- Completing milestones 1 and 2 is a B+
- Completing milestones 1 and 4 is a B 


## Files and Directories:

**Report.pdf** - 
Our report for this project. Should be all that needs to be read to understand our progress.

**Setup.pdf** - 
This is how to setup Vitis. We ran into a lot of trouble and documented it so that future projects that use Vitis might reference this project.

**test** -
an update of test from https://github.com/da-steve101/radio_modulation/tree/master/c. More is explained in report.pdf.

**baseline** -
pyvgg.c contains the test in HLS for vgg10.c
vgg10.c is the baseline implementation of the modulation classification neural network
the header files are not our own, and were generated from python here: https://github.com/da-steve101/radio_modulation/tree/master/c
rpt files are also included

**optimized** -
pyvgg.c contains the test in HLS for vgg10.c
vgg10.c is the optimized implementation of the modulation classification neural network
the header files are not our own, and were generated from python here: https://github.com/da-steve101/radio_modulation/tree/master/c
rpt files are also included

**vitis_emulation** - 
These files were created by us:
host.cpp
host.h
vgg10.cpp
vgg10.h
the header files are not our own, and were generated from python here: https://github.com/da-steve101/radio_modulation/tree/master/c
the report files from emulation need to be opened in Vitis and are displayed in report.pdf
