#include <iostream>
#include <string>

using namespace std;

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void permute(string &str, int start, int end) {
    if (start == end) {
       
        cout << str << endl;
    } else {

        for (int i = start; i <= end; i++) {
            swap(str[start], str[i]);          
            permute(str, start + 1, end);      
            swap(str[start], str[i]);          
        }
    }
}

int main() {
    string str = "ABC";
    cout << "Permutations of " << str << " are:" << endl;
    permute(str, 0, str.length() - 1);
    return 0;
}
