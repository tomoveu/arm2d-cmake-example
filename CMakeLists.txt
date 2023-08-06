cmake_minimum_required(VERSION 3.15)
# ARM's CMSIS requires at least 3.15

project(arm2d_example LANGUAGES C)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DARM2D_HELPER")

include_directories(./)

include(ExternalProject)

ExternalProject_Add(arm2dlib
GIT_REPOSITORY https://github.com/ARM-software/Arm-2D.git
GIT_TAG main
UPDATE_DISCONNECTED true
CONFIGURE_COMMAND ""
CMAKE_ARGS -DARM2D_HELPER
BUILD_BYPRODUCTS ${my_arm2dlib}
)

add_executable(arm2d_hello "arm2d_hello.c")
#target_sources(arm2d_hello PRIVATE "arm2d_hello.c")
target_include_directories(arm2d_hello PRIVATE "${PROJECT_SOURCE_DIR}"
                            PRIVATE "./lib/core/Include"
                            PRIVATE "./lib/display/Include"
                            PRIVATE "./lib/core/Include")

target_link_libraries(arm2d_hello ${my_arm2dlib})