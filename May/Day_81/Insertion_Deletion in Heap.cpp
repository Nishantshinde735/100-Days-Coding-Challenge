#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    // Helper function to maintain the heap property
    void heapifyUp(int idx) {
        while (idx > 0 && heap[idx] < heap[(idx - 1) / 2]) {
            std::swap(heap[idx], heap[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

public:
    // Insert an element into the heap
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Print the heap
    void display() {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap minHeap;
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(7);
    minHeap.insert(2);

    std::cout << "Min Heap after insertion: ";
    minHeap.display();

    return 0;
}
