class Solution {
private:
    unordered_map<char, vector<char>>mp;
    void populate_map()
    {
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        
    }
    //i for digits and j for mp
    void dfs(string& digits, int i, vector<string>&endgame, string& ans)
    {
        if(i >= digits.size())
        {
            endgame.push_back(ans);
            return;
        }
        for(int j=0; j < mp[digits[i]].size(); j++)
        {
            ans+=mp[digits[i]][j];
            dfs(digits, i+1, endgame, ans);
            ans.pop_back();
        }

    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> endgame{};
        string ans{};

        if(digits.empty())return endgame;
        populate_map();
        dfs(digits, 0, endgame, ans);
        return endgame;
    }
};
