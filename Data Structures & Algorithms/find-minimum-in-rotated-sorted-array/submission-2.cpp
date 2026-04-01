class Solution {
public:
    int findMin(vector<int> &nums) {
        int last = nums.size()-1;
        if (last == 0)
        {
            return nums[0];
        }
        int s = 0;
        int e = nums.size()-1;
        int mid = (s+e)/2;
        while(s <= mid && mid < e)
        {
            cout << "s: " << s << " mid: " << mid << " e: " << e << '\n';
            if(mid < last && nums[mid] > nums[mid+1])
            {
                return nums[mid+1];
            }
            else if(mid < last && nums[mid] < nums[mid+1])
            {
                if (nums[mid] > nums[last])
                {
                    s = mid;
                }
                else 
                {
                    e = mid;
                }
                mid = (s+e)/2;
            }
        }
        if (nums[mid] > nums[e])
        {
            return nums[e];
        }
        if (nums[mid] < nums[s])
        {
            return nums[mid];
        }
        return nums[0];
    }
};
