#include <iostream>
#include <vector>

using namespace std;

void selectionSortEven(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
      
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] % 2 == 0 && (arr[minIndex] % 2 != 0 || arr[j] < arr[minIndex])) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
   
    vector<int> arr = {64, 25, 12, 22, 11, 36, 18};

    selectionSortEven(arr);

 
    cout << "Sorted array (even numbers only): ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
