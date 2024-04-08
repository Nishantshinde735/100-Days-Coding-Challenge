#include <iostream>

using namespace std;


int globalVar = 10;


void printGlobalVar() {
    cout << "Global variable inside function: " << globalVar << endl;
}

int main() {
   
    cout << "Global variable inside main function: " << globalVar << endl;

    
    globalVar = 20;
    cout << "Modified global variable inside main function: " << globalVar << endl;

    printGlobalVar();

    return 0;
}
