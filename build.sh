#!/bin/bash

# Default actions
run_tests=false

# Parse command line arguments
for arg in "$@"
do
    case $arg in
        --test)
        run_tests=true
        shift # Remove --test from processing
        ;;
        *)
        # Unknown option
        echo "Usage: $0 [--build] [--test]"
        exit 1
        ;;
    esac
done

# Directory where to build the project
build_dir="build"
CMAKE_GENERATOR=Ninja

# Function to build the project
build_project() {
        echo -e "\e[1;34mBuilding project...\e[0m"

    if [ ! -d $build_dir ]; then
        mkdir -p $build_dir
    fi
    cd $build_dir
    cmake -G "$CMAKE_GENERATOR" -DBUILD_TESTS=OFF ..
    cmake --build .
    cd -
}

# Function to build the project and tests
build_project_tests() {
    echo -e "\e[1;34mBuilding project and tests...\e[0m"

    if [ ! -d $build_dir ]; then
        mkdir -p $build_dir
    fi
    cd $build_dir
    cmake -G "$CMAKE_GENERATOR" -DBUILD_TESTS=ON ..
    cmake --build .
    cd -
}

# Function to run tests
run_tests() {
    cd $build_dir
    echo -e "\e[1;34mRunning tests...\e[0m"
    ctest --test-dir tests --output-on-failure --progress
    if [ $? -eq 0 ]; then
        echo -e "\e[1;32mTests passed.\e[0m"
    else
        echo -e "\e[1;31mTests failed.\e[0m"
    fi
    # ctest
    cd -
}

if $run_tests; then
    build_project_tests
else
    build_project
fi

if $run_tests; then
    run_tests
fi

