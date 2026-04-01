class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ilocz = 1
        ans = list([])

        if 0 in nums:
            if nums.count(0) > 1:
                for i in nums:
                    ans.append(0)
            else:
                for i in nums:
                    if i != 0:
                        ilocz*=i
                for i in nums:
                    if i == 0:
                        ans.append(ilocz)
                    else:
                        ans.append(0)         
            return ans
        else:
            for i in nums:
                ilocz *= i

            for i in nums:
                ans.append(int(ilocz/i))
            
            return ans