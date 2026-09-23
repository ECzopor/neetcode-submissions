class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       vector<bool>memo(s.size()+1, false);
       memo[s.size()] = true;

       for(int i = s.size()-1; i >= 0; i--)
       {
            for(const auto& x : wordDict)
            {
                int len = x.size();
                if(i+len <= s.size() && s.compare(i, len, x)==0)
                {
                    if(memo[i+len])
                    {
                        memo[i]=true;
                        break;
                    }
                }
            }
       }
       for(int i = s.size(); i>=0; i--)
       {
        std::cout << "memo[" << i << "]: " <<  memo[i] << '\n';
       }
       return memo[0];
    }
};
