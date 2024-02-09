# Enable testing with CTest
enable_testing()

# Make GoogleTest available
FetchContent_MakeAvailable(googletest)

# Define the test executable
add_executable(nts_tests 
    main_test.cpp
    ${PROJECT_SOURCE_DIR}/src/AndComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/NandComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/FalseComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/TrueComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/NotComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/OrComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/XorComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/NorComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/Gate4001.cpp
    ${PROJECT_SOURCE_DIR}/src/Gate4011.cpp
    ${PROJECT_SOURCE_DIR}/src/Gate4030.cpp
    ${PROJECT_SOURCE_DIR}/src/Gate4071.cpp
)
target_link_libraries(nts_tests PRIVATE GTest::gtest_main)

# Include directories
target_include_directories(nts_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(nts_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(nts_tests PRIVATE ${PROJECT_SOURCE_DIR}/src)


# Discover tests
include(GoogleTest)
gtest_discover_tests(nts_tests)