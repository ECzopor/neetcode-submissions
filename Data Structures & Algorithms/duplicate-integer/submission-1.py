class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        my_set = set({})
        for x in nums:
            my_set.add(x)

        if(len(my_set) == len(nums)):
            return False
        else:
            return True
    