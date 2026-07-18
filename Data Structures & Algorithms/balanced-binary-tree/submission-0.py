# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def help_function(self, root: Optional[TreeNode]):
        if root == None:
            return (0, True)
        h_l, s_1 = self.help_function(root.left)
        h_r, s_2 = self.help_function(root.right)
        print("we are here: ", root.val)
        print(" and lewe: ", h_l, s_1, " prawe: ",h_r, s_2)
        if s_1 == False or s_2 == False or abs(h_l - h_r) > 1:
            return (max(h_l, h_r)+1, False)
        else:
            return (max(h_l, h_r)+1, True)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        a, b = self.help_function(root)
        return b