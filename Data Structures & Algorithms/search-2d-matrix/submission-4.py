class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix) #liczba wierszy (np. 3)
        n = len(matrix[0]) #n -liczba kolumn (np. 4)
        i =0
        j = n-1
        #najpierw track down the list
        end = m-1
        start =0
        while start <= end:
            mid = (start + end)//2
            if matrix[mid][n-1] < target:
                start = mid +1
            elif matrix[mid][0] > target:
                end = mid -1
            else:
                break

        if start > end:
                return False

        end = mid

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

        