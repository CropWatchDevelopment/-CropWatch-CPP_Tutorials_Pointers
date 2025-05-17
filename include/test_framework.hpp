#pragma once

#include <iostream>
#include <functional>
#include <string>
#include <vector>

namespace testing {

class TestCase {
public:
    using TestFunction = std::function<bool()>;

    TestCase(const std::string& name, TestFunction testFunc) 
        : name_(name), testFunc_(testFunc) {}

    bool run() const {
        std::cout << "Running test: " << name_ << " ... ";
        bool result = testFunc_();
        if (result) {
            std::cout << "PASSED" << std::endl;
        } else {
            std::cout << "FAILED" << std::endl;
        }
        return result;
    }

private:
    std::string name_;
    TestFunction testFunc_;
};

class TestSuite {
public:
    TestSuite(const std::string& name) : name_(name) {}

    void addTest(const std::string& name, TestCase::TestFunction testFunc) {
        tests_.emplace_back(name, testFunc);
    }

    bool runAll() {
        std::cout << "=== Running Test Suite: " << name_ << " ===" << std::endl;
        int passed = 0;
        int failed = 0;

        for (const auto& test : tests_) {
            if (test.run()) {
                ++passed;
            } else {
                ++failed;
            }
        }

        std::cout << "=== Test Suite Summary: " << name_ << " ===" << std::endl;
        std::cout << "Passed: " << passed << ", Failed: " << failed 
                  << ", Total: " << tests_.size() << std::endl;

        return failed == 0;
    }

private:
    std::string name_;
    std::vector<TestCase> tests_;
};

} // namespace testing
