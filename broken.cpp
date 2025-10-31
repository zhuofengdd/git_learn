#include <iostream>

int main() {
    std::cout << "Starting program" << std::endl;
    int result = computeResult(42); // computeResult is not declared anywhere
    std::cout << "Result: " << result << std::endl;

    if(result = 10) { // assignment instead of comparison
        std::cout << "Result is ten!" << std::endl;
    }

    std::string text = 12345; // assigning int to string
    std::cout << text.substr(100, 10) << std::endl; // substr out of range

    undeclaredVariable += 1; // variable not declared

    return "done"; // returning const char* from int function
}
