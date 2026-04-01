class MinStack:
    
    def __init__(self):

        self.stack = [] 
        self.mini_s = []

    def push(self, val: int) -> None:
        if len(self.mini_s) == 0:
            self.mini_s.append(val)
        else:
            self.mini_s.append(min(val, self.mini_s[-1]))

        self.stack.append(val)
        

    def pop(self) -> None:
        self.stack.pop()
        self.mini_s.pop()
        

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.mini_s[-1]
        
        
