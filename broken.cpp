#include <iostream>
#include <string>

int computeResult(int value) {
    // Simple placeholder implementation that returns the input value.
    return value;
}

int main() {
    std::cout << "Starting program" << std::endl;
    int result = computeResult(42);
    std::cout << "Result: " << result << std::endl;

    if (result == 10) {
        std::cout << "Result is ten!" << std::endl;
    }

    std::string text = std::to_string(12345);
    if (text.size() > 100) {
        std::cout << text.substr(100, 10) << std::endl;
    } else {
        std::cout << "Text too short for requested substring" << std::endl;
    }

    return 0;
}
