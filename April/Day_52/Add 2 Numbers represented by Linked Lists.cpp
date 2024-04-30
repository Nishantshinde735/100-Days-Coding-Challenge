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
};

Node* addTwoNumbers(Node* l1, Node* l2) {
   
    Node* dummy = new Node(0);
    Node* current = dummy;

    int carry = 0;

  
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;

        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

    
        current->next = new Node(sum);
        current = current->next;
    }

  
    Node* resultHead = dummy->next;
    delete dummy;

    return resultHead;
}

int main() {
    LinkedList list1;
    LinkedList list2;

 
    list1.push(7);
    list1.push(1);
    list1.push(6);

   
    list2.push(5);
    list2.push(9);
    list2.push(2);

    std::cout << "First number: ";
    list1.printList();

    std::cout << "Second number: ";
    list2.printList();


    Node* resultHead = addTwoNumbers(list1.head, list2.head);
    
    
    LinkedList result;
    result.head = resultHead;

    std::cout << "Resulting sum: ";
    result.printList();

    return 0;
}
