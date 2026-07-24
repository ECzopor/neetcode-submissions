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
    int help_function(TreeNode* root, std::set<int, std::greater<int>>& s1)
    {
        if(root == nullptr)return -1;
        int max_l = help_function(root->left, s1);
        int max_r = help_function(root->right, s1);
        cout << root->val << " " << max(max_l, max_r)+1 << '\n';
        s1.insert(max_l + max_r +2);

        return std::max(max_l, max_r)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)return 0;
        std::set<int, std::greater<int>> s1{};
        int val = help_function(root, s1);
        if(val == -1)return 0;
        if(s1.size() == 0) return val;
        return std::max(*s1.begin(), val);
    }
};
