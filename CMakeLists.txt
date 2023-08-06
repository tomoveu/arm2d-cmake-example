cmake_minimum_required(VERSION 3.15)
# ARM's CMSIS requires at least 3.15

project(arm2d_example LANGUAGES C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DARM2D_HELPER")

include_directories(./)
add_subdirectory(arm2d)

add_executable(arm2d_hello "arm2d_hello.c")

target_link_libraries(arm2d_hello ${install_dir}/lib/libarm2d.lib)