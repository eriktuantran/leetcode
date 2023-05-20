mkdir build
rm -rf build/*
cd build
make clean
cmake ..
make -j8
./runUnitTests
lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info 'tests/*' '/usr/*' 'test-library*' '*modules/googletest*' '*MacOS*' --output-file coverage.info &>/dev/null
lcov --list coverage.info
cd ..
