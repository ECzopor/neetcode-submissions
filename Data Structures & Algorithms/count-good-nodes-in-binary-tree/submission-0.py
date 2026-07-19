# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def help_function(self, root:TreeNode, maks: int, good_counter: int):
        if root == None:
            return good_counter

        if maks  <= root.val:
            print("we are here: ", root.val)
            good_counter+=1
            maks = root.val
        
        good_counter = self.help_function(root.left, maks, good_counter)
        good_counter = self.help_function(root.right, maks, good_counter)
        return good_counter

    def goodNodes(self, root: TreeNode) -> int:
        return self.help_function(root, -101, 0)