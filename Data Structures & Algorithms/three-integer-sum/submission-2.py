class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = list()

        print(nums)

        for i in range(len(nums) - 2):
            print(nums[i])
            if i > 0:
                if nums[i-1] == nums[i]:
                    continue
            
            l = i+1
            r = len(nums) -1
            while l < r:
                if nums[l] + nums[r] == -1 * nums[i] :
                    ans.append([nums[i], nums[l], nums[r]])
                    l +=1
                    while nums[l] == nums[l-1] and l < r:
                        l += 1
                elif nums[l] + nums[r] < -1 * nums[i]:
                    l+=1
                else:
                    r -= 1
        return ans
        
        