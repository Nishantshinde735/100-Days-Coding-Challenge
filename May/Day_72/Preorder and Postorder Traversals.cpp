class BinaryTreeWithTraversal(BinaryTree):
    def preorder_traversal(self, node, result):
        if node:
            result.append(node.value)
            self.preorder_traversal(node.left, result)
            self.preorder_traversal(node.right, result)

    def postorder_traversal(self, node, result):
        if node:
            self.postorder_traversal(node.left, result)
            self.postorder_traversal(node.right, result)
            result.append(node.value)

    def get_preorder(self):
        result = []
        self.preorder_traversal(self.root, result)
        return result

    def get_postorder(self):
        result = []
        self.postorder_traversal(self.root, result)
        return result

# Example usage:
bt_traversal = BinaryTreeWithTraversal()
bt_traversal.insert(10)
bt_traversal.insert(5)
bt_traversal.insert(15)
bt_traversal.insert(2)
bt_traversal.insert(7)

print(bt_traversal.get_preorder())  # Output: [10, 5, 2, 7, 15]
print(bt_traversal.get_postorder()) # Output: [2, 7, 5, 15, 10]
