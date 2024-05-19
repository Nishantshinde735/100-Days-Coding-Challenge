class BinaryTreeWithHeight(BinaryTree):
    def height(self, node):
        if node is None:
            return 0
        else:
            left_height = self.height(node.left)
            right_height = self.height(node.right)
            return max(left_height, right_height) + 1

    def get_height(self):
        return self.height(self.root)

# Example usage:
bt_height = BinaryTreeWithHeight()
bt_height.insert(10)
bt_height.insert(5)
bt_height.insert(15)
bt_height.insert(2)
bt_height.insert(7)

print(bt_height.get_height())  # Output: 3
