#===============================================================================
# File: ccs_DWARE.mk
#-------------------------------------------------------------------------------
# Support for precompiled DesignWare simulation libraries
#===============================================================================
# DesignCompiler Flow Options
#    /DesignCompiler/SIMLIBS_V - List of verilog logical library names requiring 
#                      logical-to-physical mapping for simulation.
#                      May be empty.
#                      Default value of option is "" (empty list)
#    /DesignCompiler/SIMLIBS_VHD - List of VHDL logical library names requiring 
#                      logical-to-physical mapping for simulation.
#                      May be empty.
#                      Default value of option is "" (empty list)
#    /DesignCompiler/PCL_CACHE - Pathname to output of the compxlib
#                      (or compslib) utilities.
#                      May be empty.
#                      Default value of option is "" (empty string).
#    /DesignCompiler/Path - Pathname to DesignCompiler install directory
#
# Variables inside this makefile
#    DesignCompiler_SIMLIBS_V    - The value from the option /DesignCompiler/SIMLIBS_V (set in ccs_env.mk).
#    DesignCompiler_SIMLIBS_VHD  - The value from the option /DesignCompiler/SIMLIBS_VHD (set in ccs_env.mk).
#    DesignCompiler_PCL_CACHE    - The value from the option /DesignCompiler/PCL_CACHE (set in ccs_env.mk).
#
#    SIMLIBS_V    - Initialized to the value of DesignCompiler_SIMLIBS_V.
#                            If empty, this makefile does nothing.
#                            If accelerated libraries are in use, top-level makefile
#                            will initialize SIMLIBS_V to the value(s) of <techlibs>/VARS/SIMLIBS_V
#                            before appending any value from DesignCompiler_SIMLIBS_V.
#    SIMLIBS_VHD  - Initialized to the value of DesignCompiler_SIMLIBS_VHD.
#                            If empty, this makefile does nothing.
#                            If accelerated libraries are in use, top-level makefile
#                            will initialize SIMLIBS_VHD to the value(s) of <techlibs>/VARS/SIMLIBS_VHD
#                            before appending any value from DesignCompiler_SIMLIBS_VHD.
#    SIMLIBS - Combination of SIMLIBS_V and SIMLIBS_VHD (only used to determine if there is
#                          any library compilation/mapping work to be done by this makefile)
#    PCL_CACHE    - Initialized to the value of DesignCompiler_PCL_CACHE.
#                          If empty, it is set to $(PROJ_DIR)/dware_cache (to
#                          populate a precompiled library cache in the directory for this
#                          project (would be shared by all solutions).
#
#    VENDOR_LIBMAP_FILE - If SIMTOOL=msim, this variable is $(DesignCompiler_PCL_CACHE)/modelsim.ini
#                         If SIMTOOL=vcs, this variable is $(DesignCompiler_PCL_CACHE)/synopsys_sim.setup
#                         If the named file does not exist it triggers running compxlib
#                         to populate the directory based on SIMTOOL.
#                         This variable is processed by the simulator-specific makefile.
#    VENDOR_LIBMAPS_V   - This variable is a list of names
#                             <logical>.<physical>.libmapts
#                         Where <logical> is the logical library name (from SIMLIBS_V)
#                         and <physical> is the leaf directory name in PCL_CACHE.
#                         This variable is processed by the simulator-specific makefile.
#    VENDOR_LIBMAPS_VHD - This variable is a list of names
#                             <logical>.<physical>.libmapts
#                         Where <logical> is the logical library name (from SIMLIBS_VHD)
#                         and <physical> is the leaf directory name in PCL_CACHE.
#                         This variable is processed by the simulator-specific makefile.
#    VENDOR_PHYDIR      - For DesignCompiler, this variable is $(PCL_CACHE).
#                         This variable is processed by the simulator-specific makefile.
#    Variables VENDOR_LIBMAP_FILE, VENDOR_LIBMAPS_V and VENDOR_LIBMAPS_VHD must be added to the make target $(TARGET)/make_libs
#    in all supported simulator makefiles:
#        $(TARGET)/make_libs : ... $(VENDOR_LIBMAP_FILE) $(VENDOR_LIBMAPS_V) $(VENDOR_LIBMAPS_VHD)
#------------------------------------------------------------

# Get option settings from Catapult DesignCompiler Flow
PCL_CACHE        := $(DesignCompiler_PCL_CACHE)
# Add those logical library names to any list of names from the top-level makefile
ifeq "$(NETLIST)" "vhdl"
SIMLIBS_VHD         += $(DesignCompiler_SIMLIBS_VHD)
else
SIMLIBS_V           += $(DesignCompiler_SIMLIBS_V)
endif
ifeq "$(STAGE)" "gate"
ifeq "$(NETLIST)" "vhdl"
SIMLIBS_VHD         += unisim
else
SIMLIBS_V           += unisims_ver simprims_ver
endif
endif
SIMLIBS             = $(SIMLIBS_V) $(SIMLIBS_VHD)

# =============================================================================================
# Only do something if we have a precompiled library request
ifneq "$(SIMLIBS)" ""

#------------------------------------------------------------
# Determine DesignCompiler source area
SYNOPSYS := $(DesignCompiler_Path)/..

SIMULATOR := unknown
SIM_PATH := unknown

# ---------------------------------------------------------------------------------------------
# BEGIN QuestaSim SUPPORT
ifeq "$(SIMTOOL)" "msim"

MODEL_TECH := $(QuestaSIM_Path)
BANNER := $(shell $(MODEL_TECH)/vsim -version)
SIM_PATH := $(MODEL_TECH)
ifneq "$(findstring Questa,$(BANNER))" ""
  SIMULATOR := questa
else
  SIMULATOR := mti_se
endif

COMP_SIMLIB_OPTS := -32bit
ifeq "$(ModelSim_FORCE_32BIT)" "no"
# change default to empty to allow 64bit compile
COMP_SIMLIB_OPTS := 
endif

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# If the user is controlling the location of precompiled library
# mappings directly by setting the default MODELSIM_INI option
# in the QuestaSIM flow then we have nothing to do.
# So only do something for QuestaSim if no default 
# modelsim.ini file is specified.
ifeq "$(ModelSim_DEF_MODELSIM_INI)" ""

# If user's options do not specify a home or site location for precompiled libraries...
ifeq "$(PCL_CACHE)" ""
# ...default to the working directory of the project
PCL_CACHE := $(WORK_DIR)/$(WORK2PROJ)/dware_cache
# Make the directory if it doesnt exist
$(PCL_CACHE):
	-@$(ECHO) "============================================"
	-@$(ECHO) "Creating directory for DesignCompiler precompiled simulation library cache $<"
	$(MKDIR) $(subst /,$(PATHSEP),$@)
endif

# Set VENDOR_LIBMAP_FILE to mark dependency, define translate rule to run compxlib if needed
VENDOR_LIBMAP_FILE := $(PCL_CACHE)/modelsim.ini
DFI = $(subst /,$(PATHSEP),$(MODEL_TECH)/../modelsim.ini)
XDFI = $(subst /,$(PATHSEP),$(subst \,$(PATHSEP),$(DFI)))
DXDFI = $(subst $(space),\$(space),$(XDFI))
$(VENDOR_LIBMAP_FILE): MODELSIM=$(PCL_CACHE)/modelsim.ini
$(VENDOR_LIBMAP_FILE):
	-@$(ECHO) "============================================"
	-@$(ECHO) "Generating DWARE precompiled libraries"
	-@$(ECHO) "Precompiled library cache location: $(PCL_CACHE)"
	@$(MKDIR) $(subst /,$(PATHSEP),$(PCL_CACHE))
	@$(CAT) "$(XDFI)" >$(PCL_CACHE)/modelsim.ini
	$(MODEL_TECH)/vlib $(PCL_CACHE)/DWARE
	$(MODEL_TECH)/vmap DWARE $(PCL_CACHE)/DWARE
	$(MODEL_TECH)/vcom -work DWARE $(SYNOPSYS)/packages/dware/src/DWpackages*.vhd
	$(MODEL_TECH)/vcom -work DWARE $(SYNOPSYS)/packages/dware/src/DW_dp_functions_sim.vhd 
	$(MODEL_TECH)/vcom -work DWARE $(SYNOPSYS)/packages/dware/src/DWmath.vhd 
	$(MODEL_TECH)/vcom -work DWARE $(SYNOPSYS)/packages/dware/src/DW_Foundation*.vhd 
	$(MODEL_TECH)/vlib $(PCL_CACHE)/DW02
	$(MODEL_TECH)/vmap DW02 $(PCL_CACHE)/DW02
	$(MODEL_TECH)/vcom -work DW02 $(SYNOPSYS)/dw/dw02/src/DW_div.vhd
	$(MODEL_TECH)/vcom -work DW02 $(SYNOPSYS)/dw/dw02/src/DW_div_sim.vhd
	$(MODEL_TECH)/vcom -work DW02 $(SYNOPSYS)/dw/dw02/src/DW_div_pipe.vhd
	$(MODEL_TECH)/vcom -work DW02 $(SYNOPSYS)/dw/dw02/src/DW_div_pipe_sim.vhd
	

# Build list of lib mappings
VENDOR_PHYDIR := $(PCL_CACHE)
VENDOR_LIBMAPS_V   = $(foreach i,$(sort $(SIMLIBS_V)),$(TARGET)/.$(i).$(i).libmapts)
VENDOR_LIBMAPS_VHD = $(foreach i,$(sort $(SIMLIBS_VHD)),$(TARGET)/.$(i).$(i).libmapts)

# end ifeq "$(ModelSim_DEF_MODELSIM_INI)" ""
endif

# end ifeq "$(SIMTOOL)" "msim"
endif
# END QuestaSim SUPPORT
# ---------------------------------------------------------------------------------------------

# end ifeq "$(SIMLIBS)" ""
endif

.PHONY: dump_VivadoLib_vars
dump_Vivado_vars:
	-@$(ECHO) "   SYNTHESIS_FLOWPKG   = $(SYNTHESIS_FLOWPKG)"
	-@$(ECHO) "   SYN_FLOW            = $(SYN_FLOW)"
	-@$(ECHO) "   DesignCompiler_SIMLIBS_V    = $(DesignCompiler_SIMLIBS_V)"
	-@$(ECHO) "   DesignCompiler_SIMLIBS_VHD  = $(DesignCompiler_SIMLIBS_VHD)"
	-@$(ECHO) "   SIMLIBS_V           = $(SIMLIBS_V)"
	-@$(ECHO) "   SIMLIBS_VHD         = $(SIMLIBS_VHD)"
	-@$(ECHO) "   SIMLIBS             = $(SIMLIBS)"
	-@$(ECHO) "   PCL_CACHE           = $(DesignCompiler_PCL_CACHE)"
	-@$(ECHO) "   VENDOR_LIBMAP_FILE  = $(VENDOR_LIBMAP_FILE)"
	-@$(ECHO) "   VENDOR_PHYDIR       = $(VENDOR_PHYDIR)"
	-@$(ECHO) "   VENDOR_LIBMAPS_V    = $(VENDOR_LIBMAPS_V)"
	-@$(ECHO) "   VENDOR_LIBMAPS_VHD  = $(VENDOR_LIBMAPS_VHD)"
	-@$(ECHO) "   ModelSim_DEF_MODELSIM_INI  = $(ModelSim_DEF_MODELSIM_INI)"
# =============================================================================================
