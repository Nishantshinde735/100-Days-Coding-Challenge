from collections import deque

class BinaryTreeWithLevelOrder(BinaryTree):
    def level_order_traversal(self):
        result = []
        if self.root is None:
            return result
        
        queue = deque([self.root])
        while queue:
            current_node = queue.popleft()
            result.append(current_node.value)
            if current_node.left:
                queue.append(current_node.left)
            if current_node.right:
                queue.append(current_node.right)
        
        return result

# Example usage:
bt_level_order = BinaryTreeWithLevelOrder()
bt_level_order.insert(10)
bt_level_order.insert(5)
bt_level_order.insert(15)
bt_level_order.insert(2)
bt_level_order.insert(7)

print(bt_level_order.level_order_traversal())  # Output: [10, 5, 15, 2, 7]
