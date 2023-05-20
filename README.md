[![Build Status](https://travis-ci.com/deftio/travis-ci-cpp-example.svg?branch=master)](https://travis-ci.com/deftio/travis-ci-cpp-example)
[![Coverage Status](https://coveralls.io/repos/github/deftio/travis-ci-cpp-example/badge.svg?branch=master)](https://coveralls.io/github/deftio/travis-ci-cpp-example?branch=master)

## Purpose:

A placeholder for leetcode challenges that I have solved.

## Use it locally:

If you want to test it all out through the common gtest procedure, first delete
**build** (if present). Then...

In the project root:

    mkdir build
    cd build
    cmake ..

By now Makefiles should be created.
Then, to build executables and do all that linking stuff,

    make

To prepare all your tests, run this:

    cmake -DBUILD_TESTS=ON ..

To setup target for coverage, run this:

    cmake -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Coverage

To run all tests easily,

    make test

Note: `cmake -DBUILD_TESTS=ON` turns on the variable 'BUILD_TESTS', which is specified in the root
CMakeLists.txt file. This is handy if you want to build in certain ways. Clear
description
[here](http://stackoverflow.com/questions/5998186/cmake-adding-command-line-options).

### Run executables

Then you can do ./myexecutable for the generated executable, e.g.:

    ./leetcode

and if you did cmake with BUILD_TESTS=ON:

    ./runUnitTests

code coverage

    ./lcov --directory . --capture --output-file coverage.info
    ./lcov --list coverage.info

# Acknowledgement and further details

This repository is based on the works of Gunnar in [this](https://github.com/grvlbit/travis-gtest-cmake-example) repository. He spent a lot of time figuring out all the details for cmake and gtest. Please refer to his repository README for more detail on his approach.
