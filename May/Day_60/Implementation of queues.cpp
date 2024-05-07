#include <iostream>

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front; 
    Node* rear; 
    
public:
  
    Queue() : front(nullptr), rear(nullptr) {}
    

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
    }
    
   
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue underflow\n";
            return -1;
        }
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }
    
    bool isEmpty() const {
        return front == nullptr;
    }
    
  
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }
    
    void printQueue() const {
        Node* current = front;
        std::cout << "Queue: ";
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
   
    Queue q;

  
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

   
    q.printQueue();

   
    std::cout << "Dequeued: " << q.dequeue() << std::endl;
    q.printQueue();

  
    std::cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << std::endl;

  
    std::cout << "Front element: " << q.peek() << std::endl;

    return 0;
}
