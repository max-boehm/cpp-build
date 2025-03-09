## C++ hello world build and test example

This is a simple C++ Hello World program with a related C++ unit test and a
Makefile.

### Build

The code can be built using a `Makefile`

```sh
$ make hello
g++ -std=c++17 -Wall -g -c -o hello.o hello.cpp
g++  -o hello hello.o -lgtest -lgtest_main

$ ./hello
Hello, World!
```

### Test

For testing the [GoogleTest](https://google.github.io/googletest/) C++ testing
framework has been used.

```sh
# install gtest library
sudo apt install libgtest-dev

# build the test
$ make hello_test
g++ -std=c++17 -Wall -g -c -o hello_test.o hello_test.cpp
g++  -o hello_test hello_test.o -lgtest -lgtest_main

# run the test
$ ./hello_test 
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from myTests
[ RUN      ] myTests.hello_is_runnable
Hello, World!
[       OK ] myTests.hello_is_runnable (3 ms)
[ RUN      ] myTests.hello_output_ok
[       OK ] myTests.hello_output_ok (3 ms)
[----------] 2 tests from myTests (6 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (6 ms total)
[  PASSED  ] 2 tests.
```

### GitHub Actions

A GitHub Actions workflow to build and test the code has been configured in
[.github/workflows/hello_action.yaml](.github/workflows/hello_action.yaml).

The workflow is invoked automatically when changes are pushed to the repository
into a branch or when a pull request is creatd (CI/CD pipeline).
