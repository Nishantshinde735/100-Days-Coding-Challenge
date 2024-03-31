#include <iostream>

using namespace std;

int main() {
    // Example numbers
    int a = 10;
    int b = 5;

    // Addition
    int sum = a + b;
    cout << "Sum: " << sum << endl;

    // Subtraction
    int difference = a - b;
    cout << "Difference: " << difference << endl;

    // Multiplication
    int product = a * b;
    cout << "Product: " << product << endl;

    // Division
    int quotient = a / b;
    cout << "Quotient: " << quotient << endl;

    // Modulo (remainder)
    int remainder = a % b;
    cout << "Remainder: " << remainder << endl;

    // Increment
    int incrementedA = ++a;
    cout << "Incremented a: " << incrementedA << endl;

    // Decrement
    int decrementedB = --b;
    cout << "Decremented b: " << decrementedB << endl;

    // Power
    int base = 2;
    int exponent = 3;
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    cout << "Power: " << result << endl;

    return 0;
}

