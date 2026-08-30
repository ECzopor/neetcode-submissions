class Solution {
public:
    void dfs(int n, vector<string>&endgame, string& ans)
    {
        if(ans.size() > n)return;
        if(ans.size() == n)
        {
            endgame.push_back(ans);
            return;
        }
        ans += "(";
        dfs(n, endgame, ans);
        ans.pop_back();
        ans += ")";
        dfs(n, endgame, ans);
        ans.pop_back();
    }

    bool is_good_par(const string& str)
    {
        int sum=0;
        for(const auto& ch : str)
        {
            if(ch == '(')sum++;
            if(ch == ')')sum--;
            if(sum < 0)return false;
        }
        if(sum != 0)return false;
        return true;
    }

    vector<string> validate(vector<string>& vec)
    {
        vector<string> ans;
        for(const auto& x : vec)
        {
            if(is_good_par(x))ans.push_back(x);
        }
        return ans;
    }

    vector<string> generateParenthesis(int n) {
        vector<string>endgame;
        string ans = "";
        dfs(n*2, endgame, ans);
        return validate(endgame);
    }
};
