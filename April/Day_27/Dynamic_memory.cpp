#include <iostream>

using namespace std;

int main() {
    
    int* ptr = new int;

  
    if (!ptr) {
        cout << "Memory allocation failed!" << endl;
        return -1;
    }

    *ptr = 100;

    cout << "Value of the dynamically allocated integer: " << *ptr << endl;

    delete ptr;

    ptr = nullptr;

    return 0;
}
