AUX_SOURCE_DIRECTORY(./ IMPL_FILES)
include_directories(include)
add_library(impl ${IMPL_FILES})