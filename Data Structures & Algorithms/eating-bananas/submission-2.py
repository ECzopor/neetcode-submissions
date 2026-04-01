class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        end = max(piles)
        start  =1
        odp = end

        while start  <= end:
            k = (end+start)//2
            suma =0
            for i in piles:
                suma += math.ceil(float(i)/k)

            if suma <= h:
                odp = k
                end = k-1
            else:
                start = k+1
        return odp
