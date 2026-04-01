class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        if not nums:
            return 0
        
        nums.sort()
        
        prev = nums[0]
        #print(prev)
        licz = 1
        maks = 0
        for i in range (1, len(nums)):
            #print(nums[i])
            if nums[i] - nums[i-1] == 1:
                #print("here: ", nums[i], " , ", nums[i-1] )
                licz += 1
            elif nums[i] != nums[i-1]:
                #print("here2: ", nums[i], " , ", nums[i-1] )
                maks = max(maks, licz)
                licz = 1

        maks = max(maks, licz)
        return maks
            
            

        
        