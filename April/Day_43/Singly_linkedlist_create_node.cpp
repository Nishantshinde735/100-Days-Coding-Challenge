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

int main() {
    Node* head = nullptr;  
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    printList(head); 
    return 0;
}
