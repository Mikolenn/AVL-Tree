cmake_minimum_required(VERSION 3.3)

# Project name and version
project(AVLTree VERSION 1.0)

# Headers
include_directories(include)
set(CMAKE_BUILD_TYPE Release)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

############# SOURCES FOR EXECUTABLE 1 ##########
# Add sources for general function tests executable
set(SOURCES test/avl_functions_tests.cpp src/functions.cpp)
file(GLOB SOURCES_EXE "src/functions.cpp" "test/avl_functions_tests.cpp")

add_compile_options("-W" "-Wall" "-pedantic")

# Add executable 1
add_executable(exe_gft ${SOURCES_EXE})

############# SOURCES FOR EXECUTABLE 2 ##########
# Add the sources for the specific test executable for avl_node_add
set(SOURCES test/avl_node_add_test.cpp src/functions.cpp)
file(GLOB SOURCES_EXE "src/functions.cpp" "test/avl_node_add_test.cpp")

add_compile_options("-W" "-Wall" "-pedantic")

# Add executable 2
add_executable(exe_nat ${SOURCES_EXE})

# Add GTest target link libraries to executable exe1
target_link_libraries(exe_gft ${GTEST_LIBRARIES} pthread)

# Add GTest target link libraries to executable exe2
target_link_libraries(exe_nat ${GTEST_LIBRARIES} pthread)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)