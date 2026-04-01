class Solution:

    def encode(self, strs: List[str]) -> str:
        if not strs:
            return "empty"
        ans = str("")
        for i in strs:
            ans += i
            ans += "\n"
        ans = ans[:-1]
        print("here:", ans)
        return ans

    def decode(self, s: str) -> List[str]:
        if s == "empty":
            return list([])
        ans = s.split("\n")
        return ans
