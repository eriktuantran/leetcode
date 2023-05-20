mkdir build
cd build
cmake ..
find . -name "*.gcda" -print0 | xargs -0 rm
make -j8
./runUnitTests
lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info 'tests/*' '/usr/*' 'test-library*' '*modules/googletest*' '*MacOS*' --output-file coverage.info &>/dev/null
lcov --list coverage.info
cd ..
