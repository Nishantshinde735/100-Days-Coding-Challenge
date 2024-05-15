class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.value = key

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        if self.root is None:
            self.root = Node(value)
        else:
            self._insert(self.root, value)

    def _insert(self, current_node, value):
        if value < current_node.value:
            if current_node.left is None:
                current_node.left = Node(value)
            else:
                self._insert(current_node.left, value)
        else:
            if current_node.right is None:
                current_node.right = Node(value)
            else:
                self._insert(current_node.right, value)

    def inorder_traversal(self, node, result):
        if node:
            self.inorder_traversal(node.left, result)
            result.append(node.value)
            self.inorder_traversal(node.right, result)

    def get_inorder(self):
        result = []
        self.inorder_traversal(self.root, result)
        return result

# Example usage:
bt = BinaryTree()
bt.insert(10)
bt.insert(5)
bt.insert(15)
bt.insert(2)
bt.insert(7)

print(bt.get_inorder())  # Output: [2, 5, 7, 10, 15]#include <iostream>
#include <vector>

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

    void inorder_traversal(Node* node, std::vector<int>& result) const {
        if (node) {
            inorder_traversal(node->left, result);
            result.push_back(node->value);
            inorder_traversal(node->right, result);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        insert(root, value);
    }

    std::vector<int> get_inorder() const {
        std::vector<int> result;
        inorder_traversal(root, result);
        return result;
    }
};

// Main function to test the BinaryTree class
int main() {
    BinaryTree bt;
    bt.insert(10);
    bt.insert(5);
    bt.insert(15);
    bt.insert(2);
    bt.insert(7);

    std::vector<int> inorder_result = bt.get_inorder();
    std::cout << "Inorder traversal: ";
    for (int value : inorder_result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}

