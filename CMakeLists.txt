cmake_minimum_required(VERSION 3.16)
project(CppPointerDemo VERSION 1.0.0 LANGUAGES CXX)

# Set C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Library with common code
add_library(pointer_lib
    src/pointer_examples.cpp
    src/additional_cpp20_features.cpp
)

# Main executable
add_executable(pointer_demo
    src/main.cpp
)
target_link_libraries(pointer_demo PRIVATE pointer_lib)

# Test executable
add_executable(pointer_tests
    tests/test_main.cpp
)
target_link_libraries(pointer_tests PRIVATE pointer_lib)

# Install
install(TARGETS pointer_demo DESTINATION bin)
