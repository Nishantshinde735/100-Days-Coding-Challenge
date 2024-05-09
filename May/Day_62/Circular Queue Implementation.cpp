#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;  
    int front; 
    int rear;  
    int capacity; 
    int size;  

public:
   
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = size = 0;
    }

   
    ~CircularQueue() {
        delete[] arr;
    }

 
    bool isEmpty() {
        return size == 0;
    }

   
    bool isFull() {
        return size == capacity;
    }


    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

   
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    
    void printQueue() {
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    
    q.printQueue();

   
    cout << "Dequeued: " << q.dequeue() << endl;
    q.printQueue();


    q.enqueue(60);
    q.enqueue(70);
    q.printQueue();

    return 0;
}
