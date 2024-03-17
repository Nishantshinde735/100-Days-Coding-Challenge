#include <iostream>
#include <vector>

std::vector<int> decimalToBinary(int decimal) {
    std::vector<int> binary;
    
    // Handle the case of 0 separately
    if (decimal == 0) {
        binary.push_back(0);
        return binary;
    }
    
    // Convert decimal to binary
    while (decimal > 0) {
        binary.push_back(decimal % 2);
        decimal /= 2;
    }
    
    // Reverse the binary representation
    std::reverse(binary.begin(), binary.end());
    
    return binary;
}

int main() {
    int decimalNumber;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;
    
    std::vector<int> binaryRepresentation = decimalToBinary(decimalNumber);
    
    // Print the binary representation
    std::cout << "Binary representation: ";
    for (int digit : binaryRepresentation) {
        std::cout << digit;
    }
    std::cout << std::endl;
    
    return 0;
}
