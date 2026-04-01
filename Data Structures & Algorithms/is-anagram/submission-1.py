class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic1 = dict({})
        for x in s:
            if x in dic1:
                dic1[x] += 1
            else:
                dic1[x] = 1
        
        dic2 = dict({})
        for x in t:
            if x in dic2:
                dic2[x] += 1
            else:
                dic2[x] = 1

        if dic1 == dic2:
            return True
        else:
            return False
            