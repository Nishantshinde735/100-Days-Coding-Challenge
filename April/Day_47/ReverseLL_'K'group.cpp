#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null\n";
}

Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr || k == 1) return head;
    
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *cur = dummy, *nex = dummy, *pre = dummy;
    int count = 0;
    
    while (cur->next != nullptr) {
        cur = cur->next;
        count++;
    }
    
    while (count >= k) {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        count -= k;
    }
    return dummy->next;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    int k = 2;
    cout << "Original list: ";
    printList(head);

    head = reverseKGroup(head, k);
    cout << "Reversed in " << k << " groups: ";
    printList(head);
    
    return 0;
}
