ifeq "$(AC_TYPES_INC)" ""
  $(error Error: The AC_TYPES_INC variable was not set. Cannot locate AC Datatypes installation)
endif
#TOT := $(shell git rev-parse --show-toplevel)

include ../../../cmod_Makefile


AC_MATH_INC = ../include
CXXFLAGS = -g -std=c++11 -I $(AC_TYPES_INC)

DEBUG_LEVEL ?= 5
USER_FLAGS +=  -DSC_INCLUDE_DYNAMIC_PROCESSES 
USER_FLAGS +=  -DCONNECTIONS_ACCURATE_SIM 
USER_FLAGS +=  -DENABLE_AXIREAD

# For CSolver
CFLAGS += -I${VCS_HOME}/include 
LIBS += ${VCS_HOME}/linux64/lib/libcsolver.so 
USER_FLAGS += -O1 -Wno-uninitialized 

all: sim_test

sim_test: $(wildcard *.h) $(wildcard *.cpp) $(wildcard $(TOT)/cmod/include/*.h)
	$(CC) $(CXXFLAGS) -I$(AC_TYPES_INC) -I$(AC_MATH_INC) -o sim_test -DHLS_CATAPULT -DDEBUG_LEVEL=$(DEBUG_LEVEL) $(CFLAGS) $(USER_FLAGS) testbench.cpp $(BOOSTLIBS) $(LIBS)
   
run:
	./sim_test $(CONFIG) $(WEIGHTS) $(INPUTS) $(OUTPUTS) $(BIAS)

sim_clean:
	rm -rf *.o sim_*

