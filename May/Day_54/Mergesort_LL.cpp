#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to add a node to the linked list
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Merge function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }

        Node* result = nullptr;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    // Function to find the middle of the linked list
    Node* findMiddle(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge sort function for linked list
    Node* mergeSort(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* middle = findMiddle(head);
        Node* left = head;
        Node* right = middle->next;
        middle->next = nullptr;

        // Recursively split and sort the left and right halves
        left = mergeSort(left);
        right = mergeSort(right);

        // Merge the sorted halves
        return merge(left, right);
    }

    // Function to sort the linked list using merge sort
    void sort() {
        head = mergeSort(head);
    }
};

int main() {
    LinkedList list;

    // Add some elements to the linked list
    list.push(5);
    list.push(1);
    list.push(3);
    list.push(8);
    list.push(2);
    list.push(7);

    std::cout << "Original linked list: ";
    list.printList();

    // Sort the linked list using merge sort
    list.sort();

    std::cout << "Sorted linked list: ";
    list.printList();

    return 0;
}
