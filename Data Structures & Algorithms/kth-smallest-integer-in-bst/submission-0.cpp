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
    int help_function(TreeNode* root, int& k, int& counter)
    {
        if(root == nullptr)
        {
            cout << "we are inside nullptr "<<'\n';;
            if(k == counter)
            {
                k--;
            }
            return -1;
        }
        cout << "hi we are here: " << root->val<<'\n';;
        int num = help_function(root->left, k, counter);
        if(num != -1)return num;

        cout << "back" << '\n';
        if(counter==0)return root->val;

        if(counter != k)
        {
            cout << "hi we are moving up on: " << root->val<<'\n';
            k--;
        }

        num = help_function(root->right, k, counter);
        if(num != -1)return num;
        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        return help_function(root, k, k);
    }
};
