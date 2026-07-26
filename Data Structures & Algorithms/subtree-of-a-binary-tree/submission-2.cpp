/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool help_func (TreeNode* root, TreeNode* sub)
    {  
        if (root == nullptr && sub == nullptr) return true;
        if (root == nullptr || sub == nullptr) return false;
        if(root->val != sub->val)return false;
        return help_func(root->left, sub->left) && help_func(root->right, sub->right);
    }



    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr)return false;
        if(root->val == subRoot->val)
        {
            if(help_func(root,subRoot))return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

};
