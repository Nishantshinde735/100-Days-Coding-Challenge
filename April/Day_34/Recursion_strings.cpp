#include <iostream>
#include <string>

using namespace std;

string reverseString(const string& str) {

    if (str.empty() || str.length() == 1) {
        return str;
    }

    
   return reverseString(str.substr(1)) + str[0];
}

int main() {
    string input;

  
    cout << "Enter a string: ";
    getline(cin, input);
  
    string reversed = reverseString(input);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
