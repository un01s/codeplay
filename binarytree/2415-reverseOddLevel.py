"""
2415 reverse odd level
check the invert-tree first

"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(node1: Optional[TreeNode], node2: Optional[TreeNode], is_odd: bool):
            if node1 is None: return
            if is_odd: 
                node1.val, node2.val = node2.val, node1.val 
            dfs(node1.left, node2.right, not is_odd)
            dfs(node1.right, node2.left, not is_odd)
        dfs(root.left, root.right, True)
        return root; 

