class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        #i rlly tried
        #giving up tho, and doing n^2
        ls = list([])

        for i in range(len(temperatures) -1):
            ans = 1
            j = i+1
            while j < len(temperatures) and temperatures[i] >= temperatures[j]:
                ans += 1
                j += 1
                if j == len(temperatures):
                    ans = 0
            ls.append(ans)
        ls.append(0)
        return ls

                    
        
          