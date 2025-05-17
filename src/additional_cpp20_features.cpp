#include "../include/cpp20_utils.hpp"
#include "../include/additional_cpp20_features.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

// This is an additional source file to demonstrate more C++20 features
void demonstrateAdditionalCpp20Features() {
    std::cout << "\n=== Additional C++20 Features Example ===" << std::endl;
    
    // Using C++20 designated initializers
    cpp20_utils::Point p{.x = 10, .y = 20};
    std::cout << "Point: (" << p.x << ", " << p.y << ")" << std::endl;
    
    // Using C++20 structured binding with our custom function
    auto [x, y] = p.as_tuple();
    std::cout << "Structured binding: x=" << x << ", y=" << y << std::endl;
    
    // Using C++20 comparison
    cpp20_utils::Version v1{.major = 1, .minor = 0, .patch = 0};
    cpp20_utils::Version v2{.major = 2, .minor = 0, .patch = 0};
    
    if (v1 < v2) {
        std::cout << "Version 1.0.0 is less than Version 2.0.0" << std::endl;
    }
    
    // Demonstrating container printing with concepts
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Vector using the print_container utility: ";
    cpp20_utils::print_container(numbers);
    
    // Filter even numbers manually
    std::cout << "Even numbers: ";
    std::vector<int> evenNumbers;
    for (int n : numbers) {
        if (n % 2 == 0) {
            evenNumbers.push_back(n);
        }
    }
    cpp20_utils::print_container(evenNumbers);
    
    // Demonstrating floating_point concept constraint
    std::vector<double> temperatures = {22.5, 23.1, 19.8, 21.4, 24.0};
    std::cout << "Average temperature: " << cpp20_utils::average(temperatures) << std::endl;
}
