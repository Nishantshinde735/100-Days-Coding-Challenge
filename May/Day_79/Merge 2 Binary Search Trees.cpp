#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal and store the elements in a vector
void inorderTraversal(TreeNode* root, std::vector<int>& elements) {
    if (root == nullptr) return;
    inorderTraversal(root->left, elements);
    elements.push_back(root->val);
    inorderTraversal(root->right, elements);
}

// Function to merge two sorted arrays into one sorted array
std::vector<int> mergeSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }
    return merged;
}

// Function to convert a sorted array to a balanced BST
TreeNode* sortedArrayToBST(const std::vector<int>& sortedArray, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode* node = new TreeNode(sortedArray[mid]);
    node->left = sortedArrayToBST(sortedArray, start, mid - 1);
    node->right = sortedArrayToBST(sortedArray, mid + 1, end);
    return node;
}

// Function to merge two BSTs into a single BST
TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
    std::vector<int> elements1, elements2;
    inorderTraversal(root1, elements1);
    inorderTraversal(root2, elements2);
    std::vector<int> mergedElements = mergeSortedArrays(elements1, elements2);
    return sortedArrayToBST(mergedElements, 0, mergedElements.size() - 1);
}

// Function to print the inorder traversal of a BST
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Creating first BST
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    // Creating second BST
    TreeNode* root2 = new TreeNode(7);
    root2->left = new TreeNode(6);
    root2->right = new TreeNode(8);

    // Merging the two BSTs
    TreeNode* mergedRoot = mergeBSTs(root1, root2);

    // Printing the inorder traversal of the merged BST
    std::cout << "Inorder traversal of the merged BST: ";
    printInorder(mergedRoot);
    std::cout << std::endl;

    return 0;
}
