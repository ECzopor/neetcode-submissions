class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        #lets try an array with Xs
        id =0
        while nums[id] != 'X':
            temp  =nums[id]
            nums[id] = 'X'
            id = temp
        return id        