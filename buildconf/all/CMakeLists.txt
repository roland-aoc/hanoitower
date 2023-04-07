cmake_minimum_required(VERSION 3.16.1)
project(hanoitower_proj)

include(../base/CMakeLists.txt)

##############################################################################################################################
# EXECUTABLES
##############################################################################################################################

add_executable(main ${CMAKE_SOURCE_DIR}/main.cpp)
add_executable(nonius_runner ${CMAKE_SOURCE_DIR}/nonius_runner.cpp)
add_executable(test_runner ${CMAKE_SOURCE_DIR}/tests/test_runner.h)

##############################################################################################################################
# LIBRARY DEFINITION
##############################################################################################################################

add_library(hanoitower_lib SHARED)
add_library(hanoitower_test_lib SHARED)
add_library(nonius_lib SHARED)

##############################################################################################################################
# NATIVE DEPENDENCY
##############################################################################################################################

find_package(Threads) #for nonius

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

find_package(GTest REQUIRED) # after: sudo apt-get install libgtest-dev
include_directories(${GTEST_INCLUDE_DIRS})

include(GoogleTest)

find_package(spdlog)
target_link_libraries(main PRIVATE spdlog::spdlog) # ${numeric_INCLUDE_DIRS}

##############################################################################################################################
# SINGLE-STATED HEADER DEPENDENCY
##############################################################################################################################

file(GLOB NONIUS_FILES
     "${CMAKE_SOURCE_DIR}/include/nonius-1.1.2-release/nonius.h++"
     "${CMAKE_SOURCE_DIR}/common_test.h"
)
target_sources(nonius_lib PRIVATE ${NONIUS_FILES})
set_target_properties(nonius_lib PROPERTIES LINKER_LANGUAGE CXX)

# ### ENABLE
target_link_libraries(
     nonius_runner
     PRIVATE
          nonius_lib
          ${CMAKE_THREAD_LIBS_INIT} #from Threads
)

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

target_link_libraries(
     nonius_runner
     PUBLIC
          ${HDRS_FILES}
     PRIVATE
          ${IMPL_FILES}
)

##############################################################################################################################
# TESTS
##############################################################################################################################

file(GLOB TEST_FILES
     "${CMAKE_SOURCE_DIR}/tests/game_test.cpp"
)

target_sources(hanoitower_test_lib PRIVATE ${TEST_FILES})
set_target_properties(test_runner PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(
     test_runner
     PUBLIC
          ${HDRS_FILES}
     PRIVATE
          ${IMPL_FILES}
          hanoitower_test_lib 
          GTest::gtest_main
)

enable_testing()
gtest_discover_tests(test_runner)

# not strictly needed
# include(CTest)