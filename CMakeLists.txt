cmake_minimum_required(VERSION 3.10.0)
#详细样例参考 https://github.com/kigster/cmake-project-template  https://github.com/district10/cmake-templates/tree/master/modules 工程
project(exmample)

# Set the searching location for cmake 'include' locations
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-module;")

include(c++-standards)
include(sanitizers)
include(doxygen)
#include(code-coverage)
#include(formatting)
include(tools)
#include(dependency-graph)



# Require C++11
cxx_11()

# build doc
build_docs(PROCESS_DOXYFILE TARGET_NAME doc DOXYFILE_PATH Doxyfile.in)

add_subdirectory(asio/chat)
add_subdirectory(program_options)
