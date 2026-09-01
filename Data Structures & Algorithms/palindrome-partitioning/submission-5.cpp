class Solution {
public:
    bool is_poli(const string& s, int i, int j)
    {
        while(i < j)
        {
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }


    void all_substr(string& s, vector<vector<string>>& endgame, int i, vector<string>& ans)
    {
        if(i >= s.size())
        {   
            endgame.push_back(ans);
            return;
        }
        for(int j =i; j < s.size(); j++)
        {
            if(is_poli(s, i, j))
            {
                ans.push_back(s.substr(i, j-i+1));
                all_substr(s, endgame, j+1, ans);
                ans.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> endgame{};
        vector<string> ans;
        all_substr(s, endgame, 0, ans);
        return endgame;
    }
};