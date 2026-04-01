class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        new_s = str("")
        for i in s:
            if 47 < ord(i) < 58 or 96 < ord(i) < 123:
                new_s += i
        print(new_s)

        for i in range (len(new_s)//2):
            if new_s[i] != new_s[len(new_s) -1 -i]:
                print("1: ", new_s[i], " last: ", new_s[len(new_s) -1 -i])
                return False;
        return True
        