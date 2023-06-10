cmake_minimum_required(VERSION 3.15)
# ARM's CMSIS requires at least 3.15

project(arm2d_example LANGUAGES C)

file(GLOB arm2d_core_sources ./lib/core/Source/**.c ./lib/core/Include/**.h)
SET( arm2d_hello ${arm2d_core_sources})
    
file(GLOB arm2d_display_sources ./lib/display/Source/**.c ./lib/display/Include/**.h)
SET( arm2d_hello ${arm2d_display_sources})

add_executable(arm2d_hello "arm2d_hello.c" ${arm2d_core_sources} ${arm2d_display_sources})

#target_sources(arm2d_hello PRIVATE "arm2d_hello.c")
target_include_directories(arm2d_hello PRIVATE "${PROJECT_SOURCE_DIR}"
                            PRIVATE "./lib/core/Include"
                            PRIVATE "./lib/display/Include"
                            PRIVATE "./lib/core/Include")

#    add_subdirectory(lib/core)
#    add_subdirectory(lib/display)

# pull in common dependencies
target_link_libraries(arm2d_hello)
