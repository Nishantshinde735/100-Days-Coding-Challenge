#include <iostream>
#include <string>

std::string decimalToBinary(int n) {
    std::string binary = "";
    if (n == 0) {
        return "0";
    }
    while (n > 0) {
        // Append '0' or '1' depending on the remainder
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n = n / 2;
    }
    return binary;
}

int main() {
    int number;
    std::cout << "Enter a decimal number: ";
    std::cin >> number;

    std::string binaryRepresentation = decimalToBinary(number);
    std::cout << "Binary representation: " << binaryRepresentation << std::endl;

    return 0;
}
