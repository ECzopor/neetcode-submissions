class Solution {
public:
    void help_funcion (vector<int>& nums, int target, vector<int>& ans, int sum, int i, vector<vector<int>>& endgame)
    {
        if(i >= nums.size())return;
        if(sum > target)return;
        if(sum == target)
        {
            endgame.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        help_funcion(nums, target, ans, sum+nums[i], i, endgame);
        ans.pop_back();
        help_funcion(nums, target, ans, sum, i+1, endgame);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> endgame{};
        vector<int>ans{};
        help_funcion(nums, target, ans, 0, 0, endgame);
        return endgame;
    }
};
