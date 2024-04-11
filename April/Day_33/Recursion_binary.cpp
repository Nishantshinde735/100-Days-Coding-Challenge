#include <iostream>
#include <vector>

using namespace std;

int binarySearchRecursive(const vector<int>& arr, int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

     
        if (arr[mid] == target) {
            return mid;
        }


        if (arr[mid] > target) {
            return binarySearchRecursive(arr, left, mid - 1, target);
        }

        return binarySearchRecursive(arr, mid + 1, right, target);
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    int n = arr.size();
    int result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
