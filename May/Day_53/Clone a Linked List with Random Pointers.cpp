#include <iostream>
#include <unordered_map>

using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int data) : data(data), next(nullptr), random(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

  
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            int randomData = (temp->random) ? temp->random->data : -1;
            cout << "Data = " << temp->data << ", Random = " << randomData << "\n";
            temp = temp->next;
        }
    }

   
    Node* clone() {
        Node* curr = head;
        Node* temp = nullptr;

        
        while (curr) {
            temp = curr->next;
            curr->next = new Node(curr->data);
            curr->next->next = temp;
            curr = temp;
        }

        curr = head;

        
        while (curr) {
            curr->next->random = (curr->random) ? curr->random->next : curr->random;
            curr = curr->next->next;
        }

        Node* original = head, *copy = head->next;

        
        temp = copy;

        
        while (original && copy) {
            original->next = original->next->next;
            copy->next = (copy->next) ? copy->next->next : copy->next;
            original = original->next;
            copy = copy->next;
        }

        return temp;
    }
};

int main() {
    LinkedList list;
    list.push(5);
    list.push(4);
    list.push(3);
    list.push(2);
    list.push(1);

   
    list.head->random = list.head->next->next; 
    list.head->next->random = list.head->next->next->next; 
    list.head->next->next->random = list.head; 
    list.head->next->next->next->random = list.head->next; 
    list.head->next->next->next->next->random = list.head->next->next->next->next; 

    cout << "Original list:\n";
    list.printList();

    Node* clonedList = list.clone();

    LinkedList clonedLinkedList;
    clonedLinkedList.head = clonedList;

    cout << "Cloned list:\n";
    clonedLinkedList.printList();

    return 0;
}
