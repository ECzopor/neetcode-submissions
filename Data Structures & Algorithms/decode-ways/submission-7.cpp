class Solution {
public:
    int numDecodings(string s) {
        int old=0;
        int prev =1;

        for(int i=s.length()-1; i >=0; i--)
        {
            int curr=0;
            if(s[i] == '0')
            {
                curr=0;
                old = prev;
                prev = curr;
                continue;
            }
            if(i+1 < s.length())
            {
                int temp = s[i] - '0';
                temp *=10;
                temp += s[i+1] - '0';
                if(temp < 27)curr += old;

            }
            curr+=prev;
            old = prev;
            prev = curr;
        }
        return prev;

    }
};
