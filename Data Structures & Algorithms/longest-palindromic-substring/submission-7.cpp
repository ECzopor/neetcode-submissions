class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <2)return s;
        string ans = s.substr(0, 1);
        for(int i=0; i < s.size(); i++)
        {
            int l=i, r=i;
            string temp="";
            while(l >= 0 && r < s.length() && s[l] ==s[r])
            {
                if(r-l+1 > ans.length()) temp= s.substr(l, r-l+1);
                l--;
                r++;
            }
            if(temp.length() > ans.length())ans = temp;

            l=i, r=i+1;
            temp="";
            while(l >= 0 && r < s.length() && s[l] ==s[r])
            {
                if(r-l+1 > ans.length()) temp= s.substr(l, r-l+1);
                l--;
                r++;
            }
            if(temp.length() > ans.length())ans = temp;
        }
        return ans;
    }
};
