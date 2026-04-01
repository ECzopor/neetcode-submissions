class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dic = dict({})
        for i in nums:
            if i in dic:
                dic[i] +=1 
            else:
                dic[i] = 1
        vals = list(dic.values())
        key = list(dic.keys())
        cop = vals.copy()
        cop.sort(reverse=True)

        print("vals: ", vals)
        print("key: ", key)
        print("cop: ", cop)

        ans = list([])

        for i in range(k):
            x = vals.index(cop[i])
            ans.append(key[x])
            vals.pop(x)
            key.pop(x)
        
        return ans


        