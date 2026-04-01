class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        ans = list([])
        while len(strs) > 0:
            temp = list([strs[0]])
            j = 1
            while j < len(strs):
                if sorted(strs[0]) == sorted(strs[j]):
                    temp.append(strs[j])
                    strs.pop(j)
                else:
                    j += 1
            strs.pop(0)
            ans.append(temp.copy())
            temp.clear()
        return ans




