class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start = int(0)
        end = int(len(nums))
        mid = int((start + end) // 2)

        while nums[mid] != target:
            if mid == start or mid == end:
                return -1
            if nums[mid] < target:
                start = mid
            else:
                end = mid
            mid = (start + end)//2
            

        if end <= start:
            return -1
        else:
            return mid
        