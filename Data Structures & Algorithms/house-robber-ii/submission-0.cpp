class Solution {
public:
    int rob(vector<int>& nums) {
        int older =0;
        int prev = nums[0];

        for(int i=1; i<nums.size()-1; i++)
        {
            int temp = max(older+nums[i], prev);
            older = prev;
            prev = temp;

        }
        int max_1 = prev;
        older = 0;
        prev = nums[nums.size()-1];

        for(int i=nums.size()-2; i >0; i--)
        {
            int temp = max(older+nums[i], prev);
            older = prev;
            prev = temp;
        }

        return max(max_1, prev);
       
    }
};
