#include <iostream>
#include <string>
#include <unordered_map>

std::string hexToBinary(char hexDigit) {
    static const std::unordered_map<char, std::string> hexToBin{
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
        {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
        {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
        {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}
    };
    return hexToBin.at(hexDigit);
}

std::string hexStringToBinary(const std::string& hexString) {
    std::string binaryString;
    for (char hexDigit : hexString) {
        if (hexDigit >= '0' && hexDigit <= '9') {
            binaryString += hexToBinary(hexDigit);
        } else if (hexDigit >= 'A' && hexDigit <= 'F') {
            binaryString += hexToBinary(hexDigit);
        } else if (hexDigit >= 'a' && hexDigit <= 'f') {
            binaryString += hexToBinary(toupper(hexDigit)); // Convert lowercase to uppercase
        } else {
            std::cerr << "Invalid hexadecimal digit: " << hexDigit << std::endl;
            return ""; // Return empty string for invalid input
        }
    }
    return binaryString;
}

int main() {
    std::string hexNumber;
    std::cout << "Enter a hexadecimal number: ";
    std::cin >> hexNumber;

    std::string binaryRepresentation = hexStringToBinary(hexNumber);
    if (!binaryRepresentation.empty()) {
        std::cout << "Binary representation: " << binaryRepresentation << std::endl;
    }

    return 0;
}
