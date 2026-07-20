# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def help_function(self, root:Optional[TreeNode], small: int, big: int):
        if root == None:
            return True
        if small >= root.val or big <= root.val:
            return False
        return self.help_function(root.left, small, root.val) and self.help_function(root.right, root.val, big)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.help_function(root, -1001, 1001)