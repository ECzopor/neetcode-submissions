class Solution:
    def trap(self, height: List[int]) -> int:
        pocz, kon = 0, len(height)-1
        water = 0

        while pocz < kon:
            while(height[pocz] < 1 and pocz < len(height)-1):
                pocz +=1
            while(height[kon] < 1 and kon > 0):
                kon -= 1

            for k in range (pocz , kon+1):
                if height[k] < 1:
                    water +=1
                height[k] -= 1

        return water