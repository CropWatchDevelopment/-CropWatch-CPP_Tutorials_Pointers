#include <iostream>
#include <memory>
#include "../include/pointer_examples.hpp"
#include "../include/additional_cpp20_features.hpp"

int main() {
    std::cout << "C++20 Pointer Demonstration Program" << std::endl;


    int i = 20;
    int *iptr = &i;
    
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