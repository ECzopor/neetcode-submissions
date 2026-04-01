class MinStack:
    
    def __init__(self):

        self.stack = [] 
        self.mini = 0

    def push(self, val: int) -> None:
        self.stack.append(val)
        

    def pop(self) -> None:
        self.stack.pop()
        

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        mini = self.stack[0]
        for i in self.stack:
            if i < mini:
                mini = i
        return mini
        
        
