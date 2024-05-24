#include <iostream>
#include <vector>

class MaxHeap {
public:
    MaxHeap() {}

    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.size() > 1) {
            std::swap(heap[0], heap.back());
            heap.pop_back();
            heapifyDown(0);
        } else {
            heap.pop_back();
        }
    }

    int top() {
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(5);
    maxHeap.push(2);

    std::cout << "Max-Heap elements: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;

    return 0;
}
