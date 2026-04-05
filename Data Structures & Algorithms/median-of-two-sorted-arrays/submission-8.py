class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        short, long = nums1, nums2
        total_len = len(short)+len(long)
        partition = total_len//2

        if len(short) > len(long):
            short, long = long, short

        s,e = 0, len(short)-1

        while True:
            mid = (s+e)//2 #for short
            mid_long = partition-mid-2 #for long

            short_left =short[mid] if mid >=0 else float("-infinity")
            short_right=short[mid+1] if mid+1 < len(short) else float("infinity")
            long_left=long[mid_long] if mid_long >=0 else float("-infinity")
            long_right=long[mid_long+1]if mid_long+1 < len(long) else float("infinity")

            if short_left <= long_right and short_right >= long_left:
                if total_len%2:
                    return min(long_right, short_right)
                else:
                    return (max(short_left, long_left)+min(long_right, short_right)) /2
                
            elif short_left > long_right:
                e = mid-1
            else:
                s = mid+1
