class Solution:
    def maxArea(self, heights: List[int]) -> int:
        i = 0
        j = len(heights) - 1
        maks = (j - i) * min(heights[i], heights[j])
        print(maks)

        while i < j:
            print (i , " ", j)
            if heights[i] < heights[j]:
                i += 1
            elif heights[i] > heights[j]:
                j -=1
            else:
                while heights[i] == heights[j] and i+1 < len(heights) and j > 0:
                    if heights[j-1] < heights[i+1]:
                        i += 1
                    else:
                        j -= 1
            if i < j:
                maks = max(maks, ((j - i) * min(heights[i], heights[j])))
        
        return maks
            