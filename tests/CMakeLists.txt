# Enable testing with CTest
enable_testing()

# Make GoogleTest available
FetchContent_MakeAvailable(googletest)

# Define the test executable
add_executable(nts_tests main_test.cpp)
target_link_libraries(nts_tests GTest::gtest_main)

# Include directories
target_include_directories(nts_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(nts_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)


# Discover tests
include(GoogleTest)
gtest_discover_tests(nts_tests)