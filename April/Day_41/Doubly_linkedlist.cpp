#include <iostream>

using namespace std;


struct Node {
    int data;    
    Node* prev;  
    Node* next; 
};

Node* createNode(int data) {
    Node* newNode = new Node(); 
    newNode->data = data;      
    newNode->prev = nullptr;   
    newNode->next = nullptr;    
    return newNode;
}


void addAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data); 
   
    if (head == nullptr) {
        head = newNode;
        return;
    }

    
    newNode->next = head;
    head->prev = newNode; 
    head = newNode; 
}


void addAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data); 
    
    if (head == nullptr) {
        head = newNode;
        return;
    }

   
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

  
    temp->next = newNode;
    newNode->prev = temp;
}


void removeNode(Node*& head, int data) {
 
    if (head == nullptr) return;

 
    Node* temp = head;
    while (temp != nullptr && temp->data != data) {
        temp = temp->next;
    }


    if (temp != nullptr) {
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; 
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp; 
    }
}


void displayList(Node* head) {
    cout << "Doubly linked list: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    Node* head = nullptr; 

 
    addAtBeginning(head, 10);
    addAtBeginning(head, 20);
    addAtBeginning(head, 30);

    addAtEnd(head, 40);
    addAtEnd(head, 50);

    displayList(head);
  
    removeNode(head, 30);
    displayList(head);

    return 0;
}
