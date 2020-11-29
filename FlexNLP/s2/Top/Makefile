

# Copyright (c) 2016-2019, NVIDIA CORPORATION.  All rights reserved.
# 
# Licensed under the Apache License, Version 2.0 (the "License")
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

include ../cmod/cmod_Makefile

FLEX_SIM_DIR = /host_share/tandem_verification_demo/FlexNLP-demo/tandem_run/sim_model
FLEX_MODEL_DIR = $(FLEX_SIM_DIR)/build/CMakeFiles/flex.dir/src
FLEX_INCLUDE_DIR = -I$(FLEX_SIM_DIR)/include 

# uninterpreted_func.o: uninterpreted_func.cc $(FLEX_SIM_DIR)/include/*
# 	$(CC) $(CFLAGS) ${FLEX_INCLUDE_DIR} -c uninterpreted_func.cc -o uninterpreted_func.o $(LIBS)

all: sim_test

run:
	./sim_test

sim_test: $(wildcard *.h) $(wildcard *.cpp) $(FLEX_MODEL_DIR)/*.o uninterpreted_func.cc
	$(CC) -O3 -o sim_test $(CFLAGS) ${FLEX_INCLUDE_DIR} $(USER_FLAGS) $(wildcard *.cpp) uninterpreted_func.cc $(LIBS) $(FLEX_MODEL_DIR)/*.o

sim_clean:
	rm -rf *.o sim_*
