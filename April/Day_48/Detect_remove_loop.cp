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

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    
    void detectAndRemoveLoop() {
        Node *slow = head, *fast = head;
        
      
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                removeLoop(slow);
                return;
            }
        }
    }

private:
  
    void removeLoop(Node* loopNode) {
        Node* ptr1 = loopNode;
        Node* ptr2 = loopNode;

     
        unsigned int k = 1;
        while (ptr1->next != ptr2) {
            ptr1 = ptr1->next;
            ++k;
        }

        
        ptr1 = head;
        ptr2 = head;
        for (int i = 0; i < k; i++)
            ptr2 = ptr2->next;

       
        while (ptr2 != ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

    
        while (ptr2->next != ptr1)
            ptr2 = ptr2->next;

        ptr2->next = nullptr;
    }
};

int main() {
    LinkedList list;

    list.push(10);
    list.push(4);
    list.push(15);
    list.push(20);
    list.push(50);

   
    list.head->next->next->next->next->next = list.head->next->next;

    list.detectAndRemoveLoop();

    std::cout << "Linked List after removing loop\n";
    list.print();

    return 0;
}
