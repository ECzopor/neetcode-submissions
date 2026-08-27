class Solution {
public:
   void dfs(vector<int>& nums, vector<int>&ans, vector<vector<int>>& endgame, vector<bool>& bv)
   {
        if(ans.size() == nums.size())
        {
             endgame.push_back(ans);
             return;
        }
        for(int i =0; i < nums.size(); i++)
        {
            if(bv[i] == false)
            {
                ans.push_back(nums[i]);
                bv[i] = true;
                dfs(nums, ans, endgame, bv);
                bv[i] = false;
                ans.pop_back();
            }
        }
        
   }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>bv(nums.size(), false);
        vector<int> ans;
        vector<vector<int>>endgame;

        dfs(nums, ans, endgame, bv);
        return endgame;
    }
};
