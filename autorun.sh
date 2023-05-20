make
./runUnitTests
lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info 'tests/*' '/usr/*' 'test-library*' '*modules/googletest*' '*MacOS*' --output-file coverage.info
lcov --list coverage.info
