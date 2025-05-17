#include <iostream>
#include <memory>
#include "../include/pointer_examples.hpp"
#include "../include/additional_cpp20_features.hpp"

int main() {
    std::cout << "C++20 Pointer Demonstration Program" << std::endl;

    // Add a variable that we can inspect in the debugger
    int i = 20;
    int j = 30;
    std::cout << &i << std::endl;
    j = i; // Copy the value of i into j, not the address, so j is always 20
    int *iptr = &i;
    std::cout << *iptr << std::endl; // Dereference the pointer and printe the value
    *iptr = 42;  // Dereference the pointer, and set the value

    j = *iptr; // Copy the value of i into j, not the address, so j is always 42
    std::cout << j << std::endl; // Print the value of j
    
    // Basic pointers
    basicPointerExample();
    
    // Smart pointers
    smartPointerExample();
    
    // C++20 features
    cpp20Features();
    
    // Additional C++20 features
    demonstrateAdditionalCpp20Features();
    
    return 0;
}