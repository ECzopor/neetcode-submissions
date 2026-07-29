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
int help_function(TreeNode* root, std::set<int, std::greater<int>>& s1, int biggest_so_far)
    {
        if(root == nullptr)return biggest_so_far;
        int max_l = help_function(root->left, s1, biggest_so_far);
        int max_r = help_function(root->right, s1, biggest_so_far);
        if(root->val + max_l < root->val) max_l =0;
        if(root->val + max_r < root->val) max_r =0;

        s1.insert(max_l + max_r + root->val);

        return std::max(max_l, max_r)+ root->val;
    }
  
    
    int maxPathSum(TreeNode* root) {
        if(root == nullptr)return 0;
        std::set<int, std::greater<int>> s1{};
        int val = help_function(root, s1, -1001);
        return max(*s1.begin(), val); 
    }
};
