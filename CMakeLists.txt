cmake_minimum_required(VERSION 3.15)
# ARM's CMSIS requires at least 3.15

project(arm2d_example LANGUAGES C)

include(ExternalProject)
ExternalProject_Add(
  arm2d

  SOURCE_DIR ./arm2d
  CMAKE_ARGS -DARM2D_HELPER
)

ExternalProject_Get_Property(arm2d install_dir)
include_directories(${install_dir}/include)

add_executable(arm2d_hello "arm2d_hello.c")

add_dependencies(arm2d_hello arm2d)
target_link_libraries(arm2d_hello ${install_dir}/lib/libarm2d.lib)