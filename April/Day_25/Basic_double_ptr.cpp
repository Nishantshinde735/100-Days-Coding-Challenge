#include <iostream>
using namespace std;

int main() {
    int value = 123; 
    int* ptr = &value; 
    int** dptr = &ptr; 

    cout << "Original Value: " << value << endl;

    cout << "Value via Pointer: " << *ptr << endl;

   
    cout << "Value via Double Pointer: " << **dptr << endl;

   
    **dptr = 789;
  
    cout << "Modified Value: " << value << endl;

    return 0;
}
