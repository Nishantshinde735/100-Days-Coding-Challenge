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

    // Function to check if linked list is a palindrome
    bool isPalindrome() {
        if (head == nullptr || head->next == nullptr) {
            return true; // Empty list or single node list is always a palindrome
        }

        // Find the middle of the linked list using slow and fast pointers
        Node *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        Node* prev = nullptr;
        Node* current = slow;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Compare the first half with the reversed second half
        Node* firstHalf = head;
        Node* secondHalf = prev; // `prev` now points to the reversed second half

        while (secondHalf != nullptr) {
            if (firstHalf->data != secondHalf->data) {
                // Restore the original list (optional)
                reverseList(prev);
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Restore the original list (optional)
        reverseList(prev);
        
        return true;
    }

    // Helper function to reverse a linked list
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
};

int main() {
    LinkedList list;

    // Example: Create a linked list (e.g., 1 -> 2 -> 3 -> 2 -> 1)
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(2);
    list.push(1);

    std::cout << "Linked list: ";
    list.printList();

    // Check if the linked list is a palindrome
    if (list.isPalindrome()) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    return 0;
}
