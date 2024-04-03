#include <iostream>

using namespace std;

void increaseByTen(int &ref) {
    ref += 10; 
}

int main() {
    int value = 30;
    cout << "Original value: " << value << endl;

   
    increaseByTen(value);

   
    cout << "Value after increaseByTen function: " << value << endl;

    
    int &refValue = value; 
    refValue += 5;
   
  cout << "Value after modifying through refValue: " << value << endl;

    return 0;
}
