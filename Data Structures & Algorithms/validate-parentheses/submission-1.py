class Solution:
    def isValid(self, s: str) -> bool:
        q = deque()
        begin = list(['(', '{', "["])

        for i in s:
            if i in begin:
                q.append(i)
            else:
                if len(q) < 1:
                    return False
                elif i == ')':
                    if q[-1] != '(':
                        return False
                    else:
                        q.pop()
                elif i == '}':
                    if q[-1] != '{':
                        return False
                    else:
                        q.pop()
                elif i == ']':
                    if q[-1] != '[':
                        return False
                    else:
                        q.pop()
        
        if len(q) == 0:
            return True
        else:
            return False
        