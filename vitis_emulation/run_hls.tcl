#
# Copyright 2019 Xilinx, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Create a project
open_project -reset tw_vgg10

# Add design files
add_files vgg_dense_3.h

add_files tw_vgg10.h

add_files tw_vgg10.cpp

add_files pred_output.h

add_files dense2.h

add_files dense2.cpp

add_files dense1.h

add_files dense1.cpp

add_files conv7.h

add_files conv7.cpp

add_files conv6.h

add_files conv6.cpp

add_files conv5.h

add_files conv5.cpp

add_files conv4.h

add_files conv4.cpp

add_files conv3.h

add_files conv3.cpp

add_files conv2.h

add_files conv2.cpp

add_files conv1.h

add_files conv1.cpp

add_files bnd2_a_b.h

add_files bnd2_a_b.cpp

add_files bnd1_a_b.h

add_files bnd1_a_b.cpp

add_files bn7_a_b.h

add_files bn7_a_b.cpp

add_files bn6_a_b.h

add_files bn6_a_b.cpp

add_files bn5_a_b.h

add_files bn5_a_b.cpp

add_files bn4_a_b.h

add_files bn4_a_b.cpp

add_files bn3_a_b.h

add_files bn3_a_b.cpp

add_files bn2_a_b.h

add_files bn2_a_b.cpp

add_files bn1_a_b.h

add_files bn1_a_b.cpp

add_files -tb pyvgg.cpp

# Set the top-level function
set_top compute_network

# ########################################################
# Create a solution
open_solution -reset solution1
# Define technology and clock rate
set_part  {xczu28dr-ffvg1517-2-e}
create_clock -period 10

# Source x_hls.tcl to determine which steps to execute
# End of directives

exit


