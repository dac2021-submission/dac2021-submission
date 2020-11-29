cmake_minimum_required(VERSION 3.8)
project(cmake_tandem)

set(CMAKE_BUILD_TYPE Debug)


add_subdirectory(src)
add_subdirectory(impl)

# AUX_SOURCE_DIRECTORY(./src/ SIM_FILES)
# add_library(aes_src ${SIM_FILES})

# AUX_SOURCE_DIRECTORY(./impl/ IMPL_SRC)
# add_library(impl_src ${IMPL_SRC})

# target_include_directories(aes_src PUBLIC
#                           "${PROJECT_SOURCE_DIR}/include")

# target_include_directories(impl_src PUBLIC
#                           "${PROJECT_SOURCE_DIR}/impl")

add_executable(tandem-aes-exe app/tandem-aes.cc)
include_directories("${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/impl/include" "${PROJECT_SOURCE_DIR}/src/include")                           
target_link_libraries(tandem-aes-exe PUBLIC src impl)
link_directories( impl/build )
link_directories( src/build )

# verilate(tandem-aes-exe 
#  INCLUDE_DIRS "./verilog"
#  SOURCES ./verilog/aes_top.v
#  VERILATOR_ARGS --timescale "1ns/10ps"
# )
