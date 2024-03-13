#include <iostream>

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    int result = countSetBits(number);
    std::cout << "Number of set bits: " << result << std::endl;

    return 0;
}
