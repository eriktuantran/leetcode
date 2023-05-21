mkdir build
cd build
cmake .. -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Coverage
find . -name "*.gcda" -print0 | xargs -0 rm
make -j8

#./runUnitTests
TEST_RESULTS=./test-results
export GTEST_OUTPUT=xml:${TEST_RESULTS}/
GTEST_COLOR=1 ctest -V

lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info 'tests/*' '/usr/*' 'test-library*' '*modules/googletest*' '*MacOS*' --output-file coverage.info &>/dev/null
lcov --list coverage.info
genhtml coverage.info --output-directory html-coverage
cd ..

# Collect test results
if [ $# -eq 0 ]; then
    echo "No test report directory provided"
else
    TEST_REPORT_DIR=${1}
    mkdir -p ${TEST_REPORT_DIR}
    echo "Copying test results to ${TEST_REPORT_DIR}"
    cp -r build/coverage.info ${TEST_REPORT_DIR}
    cp -r build/html-coverage ${TEST_REPORT_DIR}
    cp -r build/test-results  ${TEST_REPORT_DIR}
fi