#include <iostream>

using namespace std;

// Inline function declaration
inline int add(int a, int b) {
    return a + b;
}

int main() {
    int result;

    // Inline function call
    result = add(5, 7);

    cout << "The sum is: " << result << endl;

    return 0;
}
