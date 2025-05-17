# C++ Pointer Demo

A demonstration of various pointer concepts in C++20, including:
- Raw pointers
- Smart pointers (unique_ptr, shared_ptr, weak_ptr)
- C++20 features (span, concepts, designated initializers, structured bindings)

## Requirements

- C++20 compatible compiler (GCC 10+, Clang 10+, or MSVC 19.30+)
- CMake 3.16 or higher (optional)

## Build and Run Options

### Using CMake

```bash
# Create a build directory
mkdir -p build && cd build

# Configure the project
cmake ..

# Build the project
make

# Run the main application
./pointer_demo

# Run the tests
./pointer_tests
```

### Using the Makefile

```bash
# Build both the main application and tests
make

# Run the main application
make run

# Run the tests
make test

# Clean up object files and executables
make clean

# Clean up everything including the build directory
make distclean

# Build using CMake (alternative)
make cmake-build
```

### Building Manually

```bash
# Build the main executable
g++ -std=c++20 -I./include -o pointer_demo src/main.cpp src/pointer_examples.cpp src/additional_cpp20_features.cpp

# Run the main executable
./pointer_demo

# Build the test executable
g++ -std=c++20 -I./include -o pointer_tests tests/test_main.cpp src/pointer_examples.cpp src/additional_cpp20_features.cpp

# Run the tests
./pointer_tests
```

## Features Demonstrated

1. **Raw Pointers**
   - Basic pointer allocation and deallocation
   - Pointer arithmetic
   - Array access

2. **Smart Pointers**
   - `std::unique_ptr` for exclusive ownership
   - `std::shared_ptr` for shared ownership
   - `std::weak_ptr` for non-owning references

3. **C++20 Features**
   - Concepts and constraints
   - `std::span` for non-owning views
   - Designated initializers
   - Structured bindings
   - Improved templates

4. **Unit Testing**
   - Simple test framework for C++ features
   - Test suites and test cases

## Project Structure

```
.
├── CMakeLists.txt
├── Makefile
├── include/
│   ├── pointer_examples.hpp
│   ├── additional_cpp20_features.hpp
│   ├── cpp20_utils.hpp
│   └── test_framework.hpp
├── src/
│   ├── main.cpp
│   ├── pointer_examples.cpp
│   └── additional_cpp20_features.cpp
├── build/
└── tests/
    └── test_main.cpp
```
