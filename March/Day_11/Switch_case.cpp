#include <iostream>

using namespace std;

int main() {
    int choice;
    
    cout << "Menu:\n";
    cout << "1. Option 1\n";
    cout << "2. Option 2\n";
    cout << "3. Option 3\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice) {
        case 1:
            cout << "You chose Option 1\n";
            break;
        case 2:
            cout << "You chose Option 2\n";
            break;
        case 3:
            cout << "You chose Option 3\n";
            break;
        default:
            cout << "Invalid choice\n";
    }
    
    return 0;
}
