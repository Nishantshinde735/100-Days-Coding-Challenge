//Using Sorting (Simple Approach):

#include <iostream>
#include <algorithm>

int kthSmallest(int arr[], int n, int k) {
    std::sort(arr, arr + n);
    return arr[k - 1];
}

int main() {
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    std::cout << "K'th smallest element is " << kthSmallest(arr, n, k) << std::endl;
    return 0;
}


//Using Min Heap (Efficient Approach)

#include <iostream>
#include <queue>

int kthSmallest(int arr[], int n, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for (int i = 0; i < n; ++i) {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
            minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    std::cout << "K'th smallest element is " << kthSmallest(arr, n, k) << std::endl;
    return 0;
}


