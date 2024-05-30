#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an unordered_map
    std::unordered_map<int, std::string> myMap;

    // Insert elements
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // Access elements
    std::cout << "Key 1: " << myMap[1] << std::endl;

    // Check existence
    if (myMap.find(2) != myMap.end()) {
        std::cout << "Key 2 found: " << myMap[2] << std::endl;
    } else {
        std::cout << "Key 2 not found" << std::endl;
    }

    // Remove an element
    myMap.erase(1);

    // Attempt to access a deleted element
    if (myMap.find(1) == myMap.end()) {
        std::cout << "Key 1 has been deleted" << std::endl;
    }

    return 0;
}
