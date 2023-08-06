cmake_minimum_required(VERSION 3.15)
# ARM's CMSIS requires at least 3.15

project(arm2d_example LANGUAGES C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DARM2D_HELPER -DARM2D_HOST")

include_directories(./)
include_directories(./math)
include_directories(./dsp)
include_directories(./common)

add_subdirectory(./arm2d)

add_executable(arm2d_hello "arm2d_hello.c")
#target_sources(arm2d_hello PRIVATE "arm2d_hello.c")
target_include_directories(arm2d_hello PRIVATE "${PROJECT_SOURCE_DIR}"
                            PRIVATE "./arm2d/core/Include"
                            PRIVATE "./arm2d/display/Include"
                            PRIVATE "./arm2d/Helper/Include"
                            PRIVATE "./arm2d/Library/Include"
                            PRIVATE "./math/"
                            PRIVATE "./dsp/"
                            PRIVATE "./common/")

target_link_libraries(arm2d_hello)
