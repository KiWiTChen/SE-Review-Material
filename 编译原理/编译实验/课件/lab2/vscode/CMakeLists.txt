cmake_minimum_required (VERSION 2.8)

project()

set(CMAKE_CXX_COMPILER "g++")

set (CMAKE_CXX_FLAGS  "-g -fexec-charset=GBK")

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(./Src SrcFiles)

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)

add_executable(Demo4 ${SrcFiles})