#include <iostream>
using namespace std;

int main() {

    int numbers[5];

    cout << "Enter 5 numbers:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }


    cout << "You entered: ";
    for (int i = 0; i < 5; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
