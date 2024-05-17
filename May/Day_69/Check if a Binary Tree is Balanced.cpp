class BinaryTreeWithBalancedCheck(BinaryTree):
    def is_balanced(self, node):
        def check_balance(node):
            if node is None:
                return 0, True
            
            left_height, left_balanced = check_balance(node.left)
            right_height, right_balanced = check_balance(node.right)
            
            balanced = left_balanced and right_balanced and abs(left_height - right_height) <= 1
            return max(left_height, right_height) + 1, balanced
        
        _, is_bal = check_balance(node)
        return is_bal

    def check_if_balanced(self):
        return self.is_balanced(self.root)

# Example usage:
bt_balanced = BinaryTreeWithBalancedCheck()
bt_balanced.insert(10)
bt_balanced.insert(5)
bt_balanced.insert(15)
bt_balanced.insert(2)
bt_balanced.insert(7)

print(bt_balanced.check_if_balanced())  # Output: True
