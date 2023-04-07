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
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-Wpedantic")
