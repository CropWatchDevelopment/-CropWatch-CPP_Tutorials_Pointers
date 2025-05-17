#include "../include/test_framework.hpp"
#include "../include/pointer_examples.hpp"
#include "../include/additional_cpp20_features.hpp"
#include "../include/cpp20_utils.hpp"
#include <memory>
#include <cassert>

// Simple test for unique_ptr functionality
bool test_unique_ptr() {
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    bool test1 = (*ptr == 42);
    
    // Test move semantics
    std::unique_ptr<int> ptr2 = std::move(ptr);
    bool test2 = (ptr.get() == nullptr);
    bool test3 = (*ptr2 == 42);
    
    return test1 && test2 && test3;
}

// Simple test for shared_ptr functionality
bool test_shared_ptr() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
    std::shared_ptr<int> ptr2 = ptr1;
    
    bool test1 = (*ptr1 == 100);
    bool test2 = (*ptr2 == 100);
    bool test3 = (ptr1.use_count() == 2);
    
    return test1 && test2 && test3;
}

// Test C++20 Point struct with designated initializers
bool test_point_struct() {
    cpp20_utils::Point p{.x = 10, .y = 20};
    bool test1 = (p.x == 10 && p.y == 20);
    
    auto [x, y] = p.as_tuple();
    bool test2 = (x == 10 && y == 20);
    
    return test1 && test2;
}

// Test C++20 Version comparison
bool test_version_comparison() {
    cpp20_utils::Version v1{.major = 1, .minor = 0, .patch = 0};
    cpp20_utils::Version v2{.major = 2, .minor = 0, .patch = 0};
    cpp20_utils::Version v3{.major = 1, .minor = 1, .patch = 0};
    
    bool test1 = (v1 < v2); // 1.0.0 < 2.0.0
    bool test2 = (v1 < v3); // 1.0.0 < 1.1.0
    bool test3 = !(v2 < v3); // !(2.0.0 < 1.1.0)
    
    return test1 && test2 && test3;
}

int main() {
    testing::TestSuite pointerTests("Pointer Tests");
    pointerTests.addTest("UniquePtr Test", test_unique_ptr);
    pointerTests.addTest("SharedPtr Test", test_shared_ptr);
    
    testing::TestSuite cpp20Tests("C++20 Feature Tests");
    cpp20Tests.addTest("Point Struct Test", test_point_struct);
    cpp20Tests.addTest("Version Comparison Test", test_version_comparison);
    
    bool pointerResult = pointerTests.runAll();
    bool cpp20Result = cpp20Tests.runAll();
    
    return (pointerResult && cpp20Result) ? 0 : 1;
}
