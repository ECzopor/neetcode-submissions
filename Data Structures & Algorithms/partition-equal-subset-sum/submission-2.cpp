class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum =0;
       for(const auto& x : nums)
       {
            sum +=x;
       } 
       if(sum%2 == 1)return false;
       int sum1 = sum/2;
       int sum2 = sum/2;
       sort(nums.begin(), nums.end());
       for(int i=nums.size()-1; i >=0; i--)
       {
            if(sum1 >= nums[i]) sum1-=nums[i];
            else if(sum2 >= nums[i]) sum2-=nums[i];
            else return false;
       }
       if(sum1==0 && sum2 == 0)return true;
       else return false;
    }
};
