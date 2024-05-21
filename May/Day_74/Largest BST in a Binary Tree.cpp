#include <iostream>
#include <climits>

// Structure for a BST node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Helper function to create a new node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Information to be returned by every node in bottom-up traversal
struct Info {
    int sz;       // Size of subtree
    int max;      // Max value in subtree
    int min;      // Min value in subtree
    int ans;      // Size of largest BST which is subtree of current node
    bool isBST;   // If subtree is BST
};

// Returns information about subtree
Info largestBSTBT(Node* root) {
    if (root == nullptr)
        return {0, INT_MIN, INT_MAX, 0, true};

    if (root->left == nullptr && root->right == nullptr)
        return {1, root->data, root->data, 1, true};

    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);

    Info ret;
    ret.sz = (1 + l.sz + r.sz);

    if (l.isBST && r.isBST && l.max < root->data && r.min > root->data) {
        ret.min = std::min(l.min, root->data);
        ret.max = std::max(r.max, root->data);
        ret.ans = l.ans + r.ans + 1;
        ret.isBST = true;
        return ret;
    }

    ret.ans = std::max(l.ans, r.ans);
    ret.isBST = false;
    return ret;
}

int main() {
    // Construct the following tree:
    //         60
    //        /  \
    //       65  70
    //      /
    //     50
    Node* root = newNode(60);
    root->left = newNode(65);
    root->right = newNode(70);
    root->left->left = newNode(50);

    std::cout << "Size of the largest BST is " << largestBSTBT(root).ans << std::endl;

    return 0;
}
