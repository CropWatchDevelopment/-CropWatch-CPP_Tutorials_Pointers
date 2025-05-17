#include "../include/pointer_examples.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <span> // C++20 feature
#include <concepts> // C++20 feature

void basicPointerExample() {
    std::cout << "\n=== Basic Pointer Example ===" << std::endl;
    
    // Raw pointer
    int* rawPtr = new int(42);
    std::cout << "Raw pointer value: " << *rawPtr << std::endl;
    delete rawPtr; // Don't forget to delete!
    
    // Array pointer
    int* arrayPtr = new int[5]{1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        std::cout << "Array element " << i << ": " << arrayPtr[i] << std::endl;
    }
    delete[] arrayPtr;
}

void smartPointerExample() {
    std::cout << "\n=== Smart Pointer Example ===" << std::endl;
    
    // unique_ptr - exclusive ownership
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(100);
    std::cout << "Unique pointer value: " << *uniquePtr << std::endl;
    
    // shared_ptr - shared ownership
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(200);
    std::shared_ptr<int> sharedPtr2 = sharedPtr1;
    std::cout << "Shared pointer value: " << *sharedPtr1 << std::endl;
    std::cout << "Shared pointer use count: " << sharedPtr1.use_count() << std::endl;
    
    // weak_ptr - non-owning reference
    std::weak_ptr<int> weakPtr = sharedPtr1;
    std::cout << "Weak pointer expired? " << weakPtr.expired() << std::endl;
    
    if (auto tempShared = weakPtr.lock()) {
        std::cout << "Weak pointer value: " << *tempShared << std::endl;
    }
}

// C++20 specific template function using concepts
template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<Numeric T>
T add(T a, T b) {
    return a + b;
}

void cpp20Features() {
    std::cout << "\n=== C++20 Features Example ===" << std::endl;
    
    // Span
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::span<int> numbersSpan(numbers);
    
    std::cout << "Using std::span to iterate: ";
    for (const auto& num : numbersSpan) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Concepts
    std::cout << "Using concepts: 5 + 3 = " << add(5, 3) << std::endl;
    std::cout << "Using concepts: 4.2 + 3.8 = " << add(4.2, 3.8) << std::endl;
}
