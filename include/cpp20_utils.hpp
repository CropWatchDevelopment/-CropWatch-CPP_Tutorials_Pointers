#pragma once

#include <algorithm>
#include <concepts>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>

namespace cpp20_utils {

// C++20 concepts
template <typename T>
concept Printable = requires(T t, std::ostream& os) {
    { os << t } -> std::convertible_to<std::ostream&>;
};

// Helper function to print any container using concepts
template <typename Container>
requires requires(Container c) { c.begin(); c.end(); }
void print_container(const Container& container, const std::string& separator = ", ") {
    for (const auto& item : container) {
        std::cout << item << separator;
    }
    std::cout << std::endl;
}

// Using C++20 constraints on template parameters
template <typename T>
requires std::is_floating_point_v<T>
T average(const std::vector<T>& values) {
    if (values.empty()) return T{};
    
    T sum = std::accumulate(values.begin(), values.end(), T{});
    return sum / static_cast<T>(values.size());
}

// Demonstrating C++20 designated initializers
struct Point {
    int x;
    int y;
    
    // Structured binding demonstration
    auto as_tuple() const {
        return std::make_tuple(x, y);
    }
};

// C++20 comparison
struct Version {
    int major;
    int minor;
    int patch;
    
    bool operator<(const Version& other) const {
        if (major != other.major) return major < other.major;
        if (minor != other.minor) return minor < other.minor;
        return patch < other.patch;
    }
    
    bool operator==(const Version& other) const {
        return major == other.major && minor == other.minor && patch == other.patch;
    }
};

} // namespace cpp20_utils
