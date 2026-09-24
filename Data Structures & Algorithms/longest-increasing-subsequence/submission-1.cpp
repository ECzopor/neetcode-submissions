class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int maks = 1;
       vector<int>vec(nums.size(), 0);
       vec[nums.size()-1] = 1;
       for(int i=nums.size()-2; i>=0; i--)
       {
            int j=i+1;
            while(j < vec.size())
            {
                
                if(nums[i] < nums[j])
                {
                    vec[i] = max(vec[i], 1+vec[j]);
                    if(vec[i] > maks)
                    {
                        maks = vec[i];
                        break;
                    }
                    
                }
                j++;
            }
            if(vec[i]==0)vec[i]=1;
       }

       for(auto x : vec)
       {
        std::cout << x << " ";
       }
       return maks; 
    }
};
