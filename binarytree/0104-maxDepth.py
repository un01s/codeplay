"""
leetcode 104
max Depth of a binary tree

why the recursive?

what is the base condition to stop the recursion?
the base condition forces the return from endless recursion.

1. Don't get into the details. Just think about the whole tree and 
its left and right subtrees.

maxDepth of the tree = max(maxDepth of left sub, maxDepth of right sub) + 1

2. 
Original problem: max depth of the tree
sub problem: max depth of either left or right sub trees

Both problems are similar. But the sub problem is embedded into another.
That is, one sub problem has to return its result to its upper-level.

The sub-problem becomes smaller and smaller, till it reaches the leaf.

For the recursive the computer is helping you and 
it keep tracking the return with the stack.
"""

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None: return 0
        l_depth = self.maxDepth(root.left)
        r_depth = self.maxDepth(root.right)
        return max(l_depth, r_depth) + 1

# 
# level traversal
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        # initialize 
        que = [root]
        depth = 0
        # start to traverse
        while que:
            n = len(que)
            for i in range(n):
                node = que.pop(0)
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
            depth += 1
        #
        return depth

# 
# another recursive
#
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        ans = 0 # global variable
        def f(node, cnt):
            if node is None:
                return
            cnt += 1
            nonlocal ans
            ans = max(ans, cnt)
            f(node.left, cnt)
            f(node.right, cnt)
        f(root, 0)
        return ans

