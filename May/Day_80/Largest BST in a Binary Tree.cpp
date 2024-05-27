#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct SubtreeInfo {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
    SubtreeInfo(bool isBST, int size, int minVal, int maxVal)
        : isBST(isBST), size(size), minVal(minVal), maxVal(maxVal) {}
};

SubtreeInfo largestBSTHelper(TreeNode* root, int& maxSize) {
    if (!root) {
        return SubtreeInfo(true, 0, INT_MAX, INT_MIN);
    }

    SubtreeInfo left = largestBSTHelper(root->left, maxSize);
    SubtreeInfo right = largestBSTHelper(root->right, maxSize);

    if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
        int size = left.size + right.size + 1;
        maxSize = std::max(maxSize, size);
        return SubtreeInfo(true, size, std::min(root->val, left.minVal), std::max(root->val, right.maxVal));
    }

    return SubtreeInfo(false, 0, 0, 0);
}

int largestBSTSubtree(TreeNode* root) {
    int maxSize = 0;
    largestBSTHelper(root, maxSize);
    return maxSize;
}

// Helper function to insert nodes into the binary tree for testing
TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    std::cout << "Size of the largest BST is " << largestBSTSubtree(root) << std::endl;

    return 0;
}
