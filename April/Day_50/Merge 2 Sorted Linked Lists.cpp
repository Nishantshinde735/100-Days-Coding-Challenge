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
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

   
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

Node* mergeTwoLists(Node* l1, Node* l2) {
  
    Node* dummy = new Node(0);
    Node* current = dummy;

   
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data <= l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    
    if (l1 != nullptr) {
        current->next = l1;
    }
    if (l2 != nullptr) {
        current->next = l2;
    }

   
    Node* mergedList = dummy->next;
    delete dummy;  // Free memory allocated to dummy node
    return mergedList;
}

int main() {
    LinkedList list1;
    LinkedList list2;

  
    list1.push(1);
    list1.push(3);
    list1.push(5);
    list1.push(7);

   
    list2.push(2);
    list2.push(4);
    list2.push(6);
    list2.push(8);

    std::cout << "First sorted list: ";
    list1.printList();

    std::cout << "Second sorted list: ";
    list2.printList();

  
    Node* mergedListHead = mergeTwoLists(list1.head, list2.head);
    
    LinkedList mergedList;
    mergedList.head = mergedListHead;
    std::cout << "Merged sorted list: ";
    mergedList.printList();

    return 0;
}
