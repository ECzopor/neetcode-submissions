class Solution {
private:
    bool safe (vector<string>& board, int j, int i)
    {
        for(int k =0; k < board.size(); k++)
        {
            if(board[k][i] == 'Q')return false;
            if(board[j][k] == 'Q')return false;           
        }
        int k=1;
        while(i+k < board.size() && j+k < board.size())
        {
            if(board[j+k][i+k] == 'Q')return false;      
            k++;
        }
        k=1;
        while(i-k >=0 && j-k >= 0)
        {
            if(board[j-k][i-k] == 'Q')return false;      
            k++;
        }
        k=1;
        while(i-k >=0 && j+k < board.size())
        {
            if(board[j+k][i-k] == 'Q')return false;      
            k++;
        }
        k=1;
        while(j-k >=0 && i+k < board.size())
        {
            if(board[j-k][i+k] == 'Q')return false;      
            k++;
        }
        return true;
    }


    void print_out(vector<string>&board)
    {
        for(const auto& s : board)
        {
            std::cout << s << '\n';
        }
        std::cout << "==========" << '\n';
    }

    void dfs(vector<string>& board, int i, vector<vector<string>>& endgame, int n)
    {
        if(i >= n)
        {
            endgame.push_back(board);
            return;
        }
        for(int j=0; j < n; j++)
        {
            if (safe(board, i, j))
            {
                board[i][j] = 'Q';
                dfs(board, i+1, endgame, n);
                board[i][j] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string help(n, '.');
        vector<string> board(n, help);
        vector<vector<string>>endgame;
       dfs(board, 0, endgame, n);
       return endgame; 
    }
};
