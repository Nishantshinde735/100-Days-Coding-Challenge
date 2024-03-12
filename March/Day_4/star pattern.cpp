#include <iostream>

int main() {
    int rows;

    // Get the number of rows from the user
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    // Nested loops to print the pattern
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}
