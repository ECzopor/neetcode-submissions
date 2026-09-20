class Solution {
public:
    unordered_map<int, int>memo;

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)return 0;
        memo[0] = 0;
        for(auto i=1; i <= amount; i++)
        {
            memo[i] = amount+1;
        }

        for(int i=1; i <= amount; i++)
        {
            for(auto c : coins)
            {
                if(i - c >= 0)
                {
                   memo[i] = min(memo[i], 1 + memo[i-c]); 
                }
            }
        }

        return memo[amount] != amount+1 ? memo[amount] : -1;
    }
};
