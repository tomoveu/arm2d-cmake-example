cmake_minimum_required(VERSION 3.15)
# ARM's CMSIS requires at least 3.15

project(arm2d_example LANGUAGES C)

include(ExternalProject)
ExternalProject_Add(
  arm2d

  SOURCE_DIR arm2d
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/arm2d
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
  BUILD_COMMAND ${MAKE_EXECUTABLE} -j -C <SOURCE_DIR>
  INSTALL_COMMAND ${MAKE_EXECUTABLE} -j -C <SOURCE_DIR> install prefix=${CMAKE_INSTALL_PREFIX}
)

ExternalProject_Get_Property(arm2d install_dir)
include_directories(${install_dir}/include)

add_executable(arm2d_hello "arm2d_hello.c" ${arm2d_core_sources} ${arm2d_display_sources})

add_dependencies(arm2d_hello arm2d)
target_link_libraries(arm2d_hello ${install_dir}/lib/libarm2d.lib)