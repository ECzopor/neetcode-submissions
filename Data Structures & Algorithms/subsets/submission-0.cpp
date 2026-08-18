class Solution {
public:
    void help_func(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans)
    {
        if(i == nums.size())
        {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        help_func(i+1, nums, subset, ans);
        subset.pop_back();
        help_func(i+1, nums, subset, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> dummy;
        help_func(0, nums, dummy, ans);
        return ans;

    }
};
