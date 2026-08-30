class Solution {
public:
    void dfs(int n, vector<string>&endgame, string& ans, int sum)
    {
        if(sum < 0)return;
        if(ans.size() > n)return;
        if(ans.size() == n)
        {
            if(sum == 0) endgame.push_back(ans);
            return;
        }
        ans += "(";
        dfs(n, endgame, ans, sum+1);
        ans.pop_back();
        ans += ")";
        dfs(n, endgame, ans, sum-1);
        ans.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string>endgame;
        string ans = "";
        dfs(n*2, endgame, ans, 0);
        return endgame;
    }
};
