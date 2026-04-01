class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = list([])
        for i in range(9):
            for j in range(9):
                if str(board[i][j]) != '.':
                    row.append(board[i][j])
            print("row: ", row)
            if len(row) > len(set(row)):
                return False
            row.clear()

        kol = list([])
        for j in range(9):
            for i in range(9):
                if str(board[i][j]) != '.':
                    kol.append(board[i][j])
            print("kol: ", kol)
            if len(kol) > len(set(kol)):
                return False
            kol.clear()

        sq = list([])
        for i in range (0, 8, 3):
            for j in range(0, 8, 3):
                for k in range(3):
                    for m in range(3):
                        if str(board[k+i][m+j]) != '.':
                            sq.append(board[k+i][m+j])
                if len(sq) > len(set(sq)):
                    return False
                sq.clear()
        return True

                
        