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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int big = max(p->val, q->val);
        int small = min(p->val, q->val);
        if(root->val >= small and root->val <= big)
        {
            return root;
        }
        else if(root->val > big)
        {
            root = root->left;
            return lowestCommonAncestor(root, p, q);
        }
        else if(root->val < small)
        {
            root = root->right;
            return lowestCommonAncestor(root, p, q);
        }
    }
};
