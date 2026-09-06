class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0; i<s.length(); i++)
        {
            cout << i << '\n';
            int add =0;
            //nieparzyste 
            while(i-add >=0 && i+add <s.length() && s[i-add] == s[i+add])
            {
                ans++;
                add++;
            }
            //parzysta
            add=0;
            while(i-add >= 0 && i+add+1 <s.length() && s[i-add] == s[i+add+1])
            {
                ans++;
                add++;
            }
        }
        return ans;
    }
};
