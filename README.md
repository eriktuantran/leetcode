[![CircleCI](https://circleci.com/gh/eriktuantran/leetcode/tree/main.svg?style=shield)](https://app.circleci.com/pipelines/github/eriktuantran/leetcode)
[![build](https://github.com/eriktuantran/leetcode/actions/workflows/main.yml/badge.svg)](https://github.com/eriktuantran/leetcode/actions)
[![codecov](https://codecov.io/gh/eriktuantran/leetcode/branch/main/graph/badge.svg?token=081P9ZNPMT)](https://codecov.io/gh/eriktuantran/leetcode)

## Purpose

A placeholder for leetcode challenges that I have been solving.

## Progress

| Index | Link                                                                            | Status |
| :---- | :------------------------------------------------------------------------------ | :----: |
| 1     | [contains-duplicate](https://leetcode.com/problems/contains-duplicate/)         |   ✅   |
| 2     | [contains-duplicate-ii](https://leetcode.com/problems/contains-duplicate-ii/)   |   ✅   |
| 3     | [contains-duplicate-iii](https://leetcode.com/problems/contains-duplicate-iii/) |   ❌   |

## Dependencies

    sudo apt-get install cmake
    sudo apt-get install lcov

Fetch the submodules (googletest):

    git submodule update --init --recursive

## Build and test (recommended)

    ./autorun.sh

## Build steps

In the project root:

    mkdir build
    cd build
    cmake ..

By now Makefiles should be created.
Then, to build executables and do all that linking stuff,

    make

To prepare all your tests, run this:

    cmake .. -DBUILD_TESTS=ON ..

To setup target for coverage, run this:

    cmake .. -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Coverage

To run all tests easily,

    make test
    or
    GTEST_COLOR=1 ctest -V

Note: `cmake -DBUILD_TESTS=ON` turns on the variable 'BUILD_TESTS', which is specified in the root
CMakeLists.txt file. This is handy if you want to build in certain ways. Clear
description
[here](http://stackoverflow.com/questions/5998186/cmake-adding-command-line-options).

### Run executables

    ./leetcode

and if you did cmake with BUILD_TESTS=ON:

    ./runUnitTests

code coverage

    cd build
    lcov --directory . --capture --output-file coverage.info
    lcov --remove coverage.info 'tests/*' '/usr/*' 'test-library*' '*modules/googletest*' '*MacOS*' --output-file coverage.info
    lcov --list coverage.info
    genhtml coverage.info --output-directory html-coverage

# Acknowledgement and further details

This repository is based on the works of Gunnar in [this](https://github.com/grvlbit/travis-gtest-cmake-example) repository. He spent a lot of time figuring out all the details for cmake and gtest. Please refer to his repository README for more detail on his approach.
