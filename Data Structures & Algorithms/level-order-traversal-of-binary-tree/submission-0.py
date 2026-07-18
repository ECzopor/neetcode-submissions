# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def help_function(self, root: Optional[TreeNode], vec: List[List[int]], lvl: int):
        if root == None:
            return vec;
        
        print(root.val, lvl)
        if len(vec) == lvl:
            vec.append([root.val])
        else:
            vec[lvl].append(root.val)
        self.help_function(root.left, vec, lvl+1)
        self.help_function(root.right, vec, lvl+1)
        return vec;

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        vec = list(list([]))
        return self.help_function(root, vec, 0)
        