"""
leetcode 110
balanced binary tree
"""

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def traverse(root):
            if not root: return 0
            left = traverse(root.left)
            if left == -1: return -1
            right = traverse(root.right)
            if right == -1: return -1
            return max(left, right) + 1 if abs(left - right) <= 1 else -1

        return traverse(root) != -1
