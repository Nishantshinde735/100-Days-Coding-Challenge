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


class LinkedList {
 private:
  Node* head;

 public:
  
  LinkedList() {
    head = nullptr;
  }

 
  void insertAtBeginning(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }
  void printList() {
    Node* temp = head;
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  LinkedList list;

  list.insertAtBeginning(3);
  list.insertAtBeginning(2);
  list.insertAtBeginning(1);

 
  cout << "Linked List: ";
  list.printList();

  return 0;
}
