make
./runUnitTests
lcov --directory . --capture --output-file coverage.info
lcov --list coverage.info