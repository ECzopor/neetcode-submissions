class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix) #liczba wierszy (np. 3)
        n = len(matrix[0]) #n -liczba kolumn (np. 4)
        i =0
        j = n-1
        #najpierw track down the list
        end = m-1
        start =0
        while start < end: #if == we good if > -1
            if matrix[start][0] < target and target < matrix[start+1][0]:
                end = start
            elif matrix[end][n-1] > target and target > matrix[end-1][n-1]:
                start = end
            else:
                if matrix[start][0] < target:
                    start +=1
                if matrix[end][n-1] > target:
                    end -= 1
        if matrix[start][0] > target:
                return False
        if matrix[end][n-1] < target:
                return False
        print("we good: ", matrix[end])
        #teraz szukamy w danym wierszu
        s = 0
        e = n
        m = (s+e)//2
        while s < m < e and matrix[end][m] != target:
            if matrix[end][m] < target:
                s = m
            else:
                e = m 
            m = (s+e) // 2
            print(f"s: {s}, m: {m}, e: {e}")
        print(f"odp {m}")
        if matrix[end][m] != target:
            return False
        else:
            return True

        