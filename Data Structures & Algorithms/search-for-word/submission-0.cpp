class Solution {
public:
    void dfs_2(vector<vector<char>>& board, bool& ans, int x, int y,const string& word, int i)
    {
        if(ans == true)return;
        if(y < 0 || x < 0 || y >= board[0].size()|| x >= board.size() || i >= word.size())return;
        if(board[x][y] == 'X')return;
        if(board[x][y] == word[i])
        {
            if(i == word.size()-1)
            {
                std::cout << "the end: " << board[x][y] <<'\n';
                ans = true;
                return;
            }
            char temp = board[x][y];
            std::cout << "addded to endgame: " << board[x][y] <<'\n';
            board[x][y] = 'X';
            
            dfs_2(board, ans, x+1, y, word, i+1);
            dfs_2(board, ans, x, y+1, word, i+1);
            dfs_2(board, ans, x-1, y, word, i+1);
            dfs_2(board, ans, x, y-1, word, i+1);
            board[x][y] = temp;
        }

    }


    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i=0; i < board.size(); i++)
        {
            for(int j=0; j < board[0].size(); j++)
            {
                
                dfs_2(board, ans, i, j, word, 0);
                if(ans)return true;
            }
        }
        return false;
    }
};
