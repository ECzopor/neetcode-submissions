class Solution {
public:
    void help_function(vector<int>& candidates, int target, vector<int>&ans, int i, int sum, vector<vector<int>>& endgame)
    {
        if(sum > target)return;
        if(sum == target)
        {
            endgame.push_back(ans);
            return;
        }
        if(i >= candidates.size())return;
        
        ans.push_back(candidates[i]);
        help_function(candidates, target, ans, i+1, sum+candidates[i], endgame);
        ans.pop_back();
        
        
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        help_function(candidates, target, ans, i+1, sum, endgame);
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> endgame;
        vector<int> ans{};
        sort(candidates.begin(), candidates.end());
        help_function(candidates, target, ans, 0, 0, endgame);

        return endgame;
    }
};
