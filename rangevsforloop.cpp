/*
In C++, a range-based for loop is a cleaner, safer syntax introduced in C++11 specifically designed to iterate through every element of a collection from beginning to end. A traditional for loop relies 
on manual indexing or explicit iterators, offering more fine-grained control over the iteration process.
*/

// Sample Of Range-Based
/*
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40};

    // "For each number in numbers..."
    for (const auto& num : numbers) { 
        std::cout << num << " ";
    }
}
*/


// Traditional Index-Based For-loop
/*
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40};

    // Manually managing the counter and bounds
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << "Index " << i << " holds " << numbers[i] << "\n";
    }
}
*/