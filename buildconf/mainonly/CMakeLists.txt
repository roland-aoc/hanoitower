##############################################################################################################################
# PROJECT DEFINITION
##############################################################################################################################

cmake_minimum_required(VERSION 3.16.1)
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

##############################################################################################################################
# EXECUTABLES
##############################################################################################################################

add_executable(main ${CMAKE_SOURCE_DIR}/main.cpp)

##############################################################################################################################
# LIBRARY DEFINITION
##############################################################################################################################

add_library(hanoitower_lib SHARED)

##############################################################################################################################
# NATIVE DEPENDENCY
##############################################################################################################################

##############################################################################################################################
# INSTALLED DEPENDENCY
##############################################################################################################################

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
set(Boost_INCLUDE_DIRS "/usr/include/boost") #after: sudo apt install boost
find_package(Boost 1.71.0)# COMPONENTS regex 

if(!Boost_FOUND)
     EXIT()
else()
     target_link_libraries(main PRIVATE hanoitower_lib ${Boost_LIBRARIES}) # ${numeric_INCLUDE_DIRS}
endif()

find_package(spdlog)
target_link_libraries(main PRIVATE spdlog::spdlog) # ${numeric_INCLUDE_DIRS}

##############################################################################################################################
# SINGLE-STATED HEADER DEPENDENCY
##############################################################################################################################

##############################################################################################################################
# HEADER DIRECTORY DEPENDENCY
##############################################################################################################################

##############################################################################################################################
# SELF-COMPILED DEPENDENCY
##############################################################################################################################

##############################################################################################################################
# SOURCE FILE LINKING
##############################################################################################################################

# most of the times any compiling error "undefined reference" is due to missing files in scope by cmake, *.h approach will mostly only read one file
file(GLOB IMPL_FILES
     "${CMAKE_SOURCE_DIR}/game/game.cpp"
     "${CMAKE_SOURCE_DIR}/game/board.cpp"
     "${CMAKE_SOURCE_DIR}/game/disk.cpp"
     "${CMAKE_SOURCE_DIR}/config.cpp"
)

file(GLOB HDRS_FILES
     "${CMAKE_SOURCE_DIR}/game/game.h"
     "${CMAKE_SOURCE_DIR}/game/board.h"
     "${CMAKE_SOURCE_DIR}/game/disk.h"
     "${CMAKE_SOURCE_DIR}/config.h"
)

target_sources(hanoitower_lib
     PRIVATE
          ${IMPL_FILES}
     PUBLIC 
     #FILE_SET HEADERS
     # BASE_DIRS .
     #FILES
          ${HDRS_FILES}
)
