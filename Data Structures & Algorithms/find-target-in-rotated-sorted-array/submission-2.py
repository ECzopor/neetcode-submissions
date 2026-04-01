class Solution:
    def search(self, nums: List[int], target: int) -> int:
        s = 0;
        e = len(nums)
        mid = (s+e)//2

        while s < e:
            
            if nums[mid] == target :
                return mid

            if nums[s] <= nums[mid]:
                if nums[s] <= target and nums[mid] >= target:
                    e = mid
                else:
                    s = mid +1
            else:
                if target >= nums[mid] and target < nums[s]:
                    s = mid +1
                else:
                    e = mid
            
            mid = (s+e)//2
            #print(f"s: {s}, nums[s]: {nums[s]}, mid: {mid}, nums[mid]: {nums[mid]},  e: {e}, nums[e]: {nums[e]}")
        return -1

