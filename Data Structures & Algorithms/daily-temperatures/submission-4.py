class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = list([])
        out = list([])
        for i in range(len(temperatures)):
            out.append(0)
    
        for i in range( len(temperatures)):
            stack.append(temperatures[i])
            j = len(stack) -2
            count = 1
            while j >= 0 and stack[j] < stack[-1]:
                stack.pop(j)
                while out[i - count] != 0:
                    count += 1
                out[i - count] = count
                count += 1
                j -= 1
            print(stack)
            print(out)
        return out



                

                    
        
          