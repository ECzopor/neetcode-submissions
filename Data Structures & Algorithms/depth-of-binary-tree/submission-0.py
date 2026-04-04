# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        print("iteration")
        if root is None:
            print("None")
            return 0
        else:
            print(root.val)
            l = self.maxDepth(root.left)
            r = self.maxDepth(root.right)
            print(l, " ", r)
        return max(l, r)+1