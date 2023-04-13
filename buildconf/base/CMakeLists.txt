##############################################################################################################################
# PROJECT DEFINITION
##############################################################################################################################

project(hanoitower_proj VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_BUILD_DIRECTORY "../../build")
set(CMAKE_SOURCE_DIR "../..")

##############################################################################################################################
# COMPILER
##############################################################################################################################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# set(CMAKE_CXX_COMPILER "C:/cygwin64/bin/g++.exe")

add_link_options()

# install(FILES $<TARGET_PDB_FILE:${PROJECT_NAME}> DESTINATION build OPTIONAL)

add_compile_options(-g)
add_compile_options(-pipe) # This flag enables the use of pipes between the compiler stages, which can reduce the amount of disk I/O required during the build process and speed up the compilation time.
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-Wpedantic")
set(CMAKE_BUILD_PARALLEL_LEVEL 4) # This flag tells the build system to use X number of threads for the compilation process. This can greatly reduce the build time on multi-core systems.

##############################################################################################################################
# SOURCE FILES
##############################################################################################################################
# most of the times any compiling error "undefined reference" is due to missing files in scope by cmake, *.h approach will mostly only read one file
file(GLOB IMPL_FILES
     "${CMAKE_SOURCE_DIR}/game/game.cpp"
     "${CMAKE_SOURCE_DIR}/game/board.cpp"
     "${CMAKE_SOURCE_DIR}/game/disk.cpp"
     "${CMAKE_SOURCE_DIR}/game/util.cpp"
     "${CMAKE_SOURCE_DIR}/config.cpp"
     )
     
     file(GLOB HDRS_FILES
     "${CMAKE_SOURCE_DIR}/game/game.h"
     "${CMAKE_SOURCE_DIR}/game/board.h"
     "${CMAKE_SOURCE_DIR}/game/disk.h"
     "${CMAKE_SOURCE_DIR}/game/util.h"
     "${CMAKE_SOURCE_DIR}/game/rods.h"
     "${CMAKE_SOURCE_DIR}/config.h"
)