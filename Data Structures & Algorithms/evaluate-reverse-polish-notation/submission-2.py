class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operators = ['+', '-', '*', '/']
        x = list([])

        for i in tokens:
            if i not in operators:
                x.append(int(i))
            else:
                if i == '+':
                    x[-2] += x[-1]
                    x.pop()
                if i == '-':
                    x[-2] -= x[-1]
                    x.pop()
                if i == '/':
                    x[-2] =  int(x[-2]/x[-1])
                    x.pop()
                if i == '*':
                    x[-2] *= x[-1]
                    x.pop()
        return x[0]
        