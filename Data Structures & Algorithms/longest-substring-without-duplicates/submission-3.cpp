class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len==0)return 0;
        int i=0;
        int j=i+1;
        set<int> chars{s[i]};
        int substr=1;
        int maks =1;
        while(j < len)
        {
            int temp = chars.size();
            chars.insert(s[j]);
            while(temp == chars.size())
            {
                chars.erase(s[i]);
                i++;
                temp = chars.size();
                chars.insert(s[j]);
            }
            substr = j-i+1;
            maks = max(maks, substr);
            j++;

        }
        maks = max(maks, substr);
        return maks;
    }
};
