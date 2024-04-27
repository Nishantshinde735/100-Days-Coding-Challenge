#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    
    void removeDuplicates() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* nextNext = current->next->next;
                delete current->next;  // Free memory
                current->next = nextNext;
            } else {
                current = current->next;
            }
        }
    }
};

int main() {
    LinkedList list;


    list.push(11);
    list.push(11);
    list.push(11);
    list.push(21);
    list.push(43);
    list.push(43);
    list.push(60);

    std::cout << "Original list:\n";
    list.printList();

    list.removeDuplicates();

    std::cout << "List after removing duplicates:\n";
    list.printList();

    return 0;
}
