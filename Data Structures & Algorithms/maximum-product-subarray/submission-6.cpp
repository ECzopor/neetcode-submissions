class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_sum = nums[0];
        int prev_min = nums[0];
        int prev_max = nums[0];
        for(int i =1; i < nums.size(); i++)
        {
            int temp;
            if(nums[i] < 0)
            {
                temp= max(nums[i], prev_min*nums[i]);
                prev_min = min(nums[i], prev_max*nums[i]);
                prev_max = temp;
                
                //std::cout << "for i: " << i << " " << nums[i] << " -> " << prev_min << " " << prev_max << " " << temp << '\n';
                //std::cout << " the min is: " << nums[i] <<  " " << prev_max*nums[i];
            }
            else
            {
                temp= max(nums[i], prev_max*nums[i]);
                prev_min = min(nums[i], prev_min*nums[i]);
                prev_max = temp;
                
            }
            if(temp > max_sum)max_sum = temp;
            
        }
        return max_sum;
    }
};
