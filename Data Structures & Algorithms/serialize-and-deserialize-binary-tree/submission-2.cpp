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

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string str="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            if(curr == nullptr)
            {
                str += "-1001,";
            }
            else{
                str += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return str;
    }

    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        string prev ="";
        vector<int>vec;
        for(char ch : data)
        {
            if(ch == ',')
            {
                vec.push_back(stoi(prev));
                prev = "";
            }
            else prev += ch;
        }
        cout << " and now the vec: " << '\n';

        for( const auto& x : vec)
        {
            cout << x << " ";
        }
        if( vec[0] == -1001)return nullptr;
        
        TreeNode* root = new TreeNode(vec[0]);
        queue<TreeNode*>q;
        q.push(root);
        int i =1;

        while(!q.empty() && i < vec.size())
        {
            TreeNode* curr = q.front();
            q.pop();

            if(vec[i] != -1001)
            {
                curr->left = new TreeNode(vec[i]);
                q.push(curr->left);
            }
            i++;

            if(vec[i] != -1001)
            {
                curr->right = new TreeNode(vec[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};
