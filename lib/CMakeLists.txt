add_library(mtc includes/matrices.hpp src/matrices.cpp)

target_include_directories(mtc PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")