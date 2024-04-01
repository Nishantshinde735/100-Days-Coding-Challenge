#include <iostream>

using namespace std;

int main() {
    int num = 10;
    int *ptr; // Declare a pointer

    ptr = &num; 
    
    cout << "Value of num: " << num << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    *ptr = 20;

    
    cout << "Modified value of num: " << num << endl;

    return 0;
}
