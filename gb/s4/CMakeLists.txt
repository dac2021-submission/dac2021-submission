cmake_minimum_required(VERSION 3.8)
project(cmake_tandem)
set(CMAKE_CXX_FLAGS -O3)

set(CMAKE_BUILD_TYPE Debug)

find_package(verilator)
if (NOT verilator_FOUND)
  message(FATAL_ERROR "Verilator was not found.")
endif()


# add_subdirectory(src)
AUX_SOURCE_DIRECTORY(./src/ SIM_FILES)
add_library(gb_src ${SIM_FILES})

target_include_directories(gb_src PUBLIC
                          "${PROJECT_SOURCE_DIR}/include")


add_executable(tandem-gb-exe app/tandem-gb.cc)
target_link_libraries(tandem-gb-exe PUBLIC gb_src)
target_include_directories(tandem-gb-exe PUBLIC
                           "${PROJECT_SOURCE_DIR}/include")

verilate(gb_src
  INCLUDE_DIRS "./verilog"
  SOURCES ./verilog/hls_target.v
  VERILATOR_ARGS --timescale "1ns/10ps" -Wno-lint -Wno-style
)