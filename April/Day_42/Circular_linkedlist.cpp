#include <iostream>

using namespace std;


struct Node {
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class CircularLinkedList {
 private:
  Node* head;

 public:

  CircularLinkedList() {
    head = nullptr;
  }

  void insertAtBeginning(int data) {
    Node* newNode = new Node(data);


    if (head == nullptr) {
      newNode->next = newNode; 
      head = newNode;
      return;
    }

   
    Node* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }

   
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
  }


  void printList() {
    if (head == nullptr) {
      cout << "List is empty" << endl;
      return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";

   
    do {
      cout << temp->data << " -> ";
      temp = temp->next;
    } while (temp != head);

    cout << "HEAD" << endl;
  }
};

int main() {
  CircularLinkedList list;

  list.insertAtBeginning(3);
  list.insertAtBeginning(2);
  list.insertAtBeginning(1);

  
  list.printList();

  return 0;
}
