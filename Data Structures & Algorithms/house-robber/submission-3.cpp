class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        if(nums.size() ==1) return nums[0];
        int old=0;
        int prev =nums[0];
        
        for(int i=1; i < nums.size(); i++)
        {
            int temp = max(old+nums[i], prev);
            old = prev;
            prev = temp;
        } 
        return prev;
    }
};
