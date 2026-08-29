class Solution {
public:
    void dfs(vector<int>&nums, vector<int>&ans, vector<vector<int>>&endgame, int i)
    {
        if(i > nums.size())return;
        if(i == nums.size())
        {
            endgame.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        dfs(nums, ans, endgame, i+1);
        int last = ans.back();
        ans.pop_back();
        while(i < nums.size()-1 && nums[i] == nums[i+1])i++;
        dfs(nums, ans, endgame, i+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans{};
        vector<vector<int>>endgame;
        dfs(nums, ans, endgame, 0); 
        return endgame;
    }
};
