cmake_minimum_required(VERSION 3.14)
project(nts VERSION 1.0 DESCRIPTION "Electronic circuit simulator" LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# For future external libraries, repeat the FetchContent_Declare and FetchContent_MakeAvailable calls here.

# Configure cmake/FindGoogleTest.cmake path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Include subdirectories
add_subdirectory(src)

if(BUILD_TESTS)
    include(FindGoogleTest)
    add_subdirectory(tests)
endif(BUILD_TESTS)
