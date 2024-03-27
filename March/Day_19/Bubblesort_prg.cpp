#include <iostream>
#include <vector>

using namespace std;


void bubbleSort(vector<int>& arr) {
    int n = arr.size();

   
    for (int i = 0; i < n - 1; ++i) {
    
        for (int j = 0; j < n - i - 1; ++j) {
          
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // Example 
    vector<int> arr = {64, 25, 12, 22, 11};

    // bubble sort
    bubbleSort(arr);

    // Output
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
