#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    
    std::unordered_map<int, std::string> myMap;

    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    std::cout << "Key 1: " << myMap[1] << std::endl;

    
    if (myMap.find(2) != myMap.end()) {
        std::cout << "Key 2 found: " << myMap[2] << std::endl;
    } else {
        std::cout << "Key 2 not found" << std::endl;
    }

    
    myMap.erase(1);

    
    if (myMap.find(1) == myMap.end()) {
        std::cout << "Key 1 has been deleted" << std::endl;
    }

    return 0;
}
