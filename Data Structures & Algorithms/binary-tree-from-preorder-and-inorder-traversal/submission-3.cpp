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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())return nullptr;
        map<int, int> mp;
        for(auto i=0; i < inorder.size(); i++)
        {
            mp[inorder[i]] =i;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        int mid = mp[preorder[0]];
        //left subtree
        vector<int>leftP(preorder.begin()+1, preorder.begin()+1+mid);
        vector<int>leftI(inorder.begin(), inorder.begin()+mid);
        root->left = buildTree(leftP, leftI);
        //right subtree
        vector<int>rightP(preorder.begin()+1+mid, preorder.end());
        vector<int>rightI(inorder.begin()+mid+1, inorder.end());
        root->right = buildTree(rightP, rightI);

        return root;
    }

    
};