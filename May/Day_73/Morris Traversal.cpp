#include <iostream>

// Node structure
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// BinaryTree class
class BinaryTree {
private:
    Node* root;

    void insert(Node* &current_node, int value) {
        if (current_node == nullptr) {
            current_node = new Node(value);
        } else if (value < current_node->value) {
            insert(current_node->left, value);
        } else {
            insert(current_node->right, value);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        insert(root, value);
    }

    void morris_inorder_traversal() const {
        Node* current = root;
        while (current != nullptr) {
            if (current->left == nullptr) {
                std::cout << current->value << " ";
                current = current->right;
            } else {
                // Find the predecessor of current
                Node* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    // Make current the right child of its predecessor
                    predecessor->right = current;
                    current = current->left;
                } else {
                    // Revert the changes made in the 'if' part to restore the original tree
                    predecessor->right = nullptr;
                    std::cout << current->value << " ";
                    current = current->right;
                }
            }
        }
    }
};

int main() {
    BinaryTree bt;
    bt.insert(10);
    bt.insert(5);
    bt.insert(15);
    bt.insert(2);
    bt.insert(7);

    std::cout << "Morris Inorder Traversal: ";
    bt.morris_inorder_traversal();
    std::cout << std::endl;

    return 0;
}
