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

    TreeNode* lvl_traverse(TreeNode* root, vector<vector<int>>& vec, int id)
    {
        if(root == nullptr)return nullptr;

        if(vec.size() == id)
        {
            vector<int> help{root->val};
            vec.push_back(help);
        }
        else vec[id].push_back(root->val);

        lvl_traverse(root->left, vec, id+1);
        lvl_traverse(root->right, vec, id+1);
        return root;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> vec{};
        lvl_traverse(root, vec, 0);
        vector<int> ans{};
        for(auto& v : vec)
        {
            ans.push_back(v.back());
        }
        return ans;
    }
};
