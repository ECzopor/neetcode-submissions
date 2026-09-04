class Solution {
public:
    int climbStairs(int n) {
        int older =1;
        if(n==1)return older;
        int prev =2;
        int i=2;
        while(i < n)
        {
            int temp = older;
            older = prev;
            prev += temp;
            i++;
        }
        return prev;
    }
};
