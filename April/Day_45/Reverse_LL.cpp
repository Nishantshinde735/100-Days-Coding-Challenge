#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};


void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}


void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}


void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;  
        current->next = prev; 
        prev = current;      
        current = next;
    }
    head = prev;  
}

int main() {
    Node* head = nullptr;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);

    cout << "Original list: ";
    printList(head);

    reverseList(head);

    cout << "Reversed list: ";
    printList(head);
    return 0;
}
