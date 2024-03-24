#include <iostream>
#include <vector>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Binary search function to find the largest prime number less than or equal to the given number
int binarySearchPrime(int low, int high) {
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPrime(mid)) {
            result = mid;
            low = mid + 1; // Search in the right half to find a larger prime
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int prime = binarySearchPrime(2, n); // Search for prime numbers between 2 and n

    if (prime != -1) {
        cout << "Largest prime number less than or equal to " << n << " is: " << prime << endl;
    } else {
        cout << "No prime number found less than or equal to " << n << endl;
    }

    return 0;
}
