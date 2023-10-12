"""
leetcode 110
balanced binary tree

this problem is an extension from 104 maxDepth
the point is to check if the depth difference between left and right subtree
exceeds 1.

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

#
# get the depth first, then check the difference
#
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        left = self.depth(root.left)
        right = self.depth(root.right)
        return abs(left-right)<2 and self.isBalanced(root.left) and self.isBalanced(root.right)

    def depth(self, node: TreeNode) -> int:
        if not node:
            return 0
        left = self.depth(root.left)
        right = self.depth(root.right)
        return 1 + max(left, right)

