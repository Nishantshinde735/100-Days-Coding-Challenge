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

Node* findMiddleNode(Node* head) {
    if (head == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    Node* head = nullptr;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "Linked list: ";
    printList(head);

    Node* middleNode = findMiddleNode(head);

    if (middleNode != nullptr) {
        cout << "Middle node data: " << middleNode->data << endl;
    } else {
        cout << "List is empty." << endl;
    }

    return 0;
}
