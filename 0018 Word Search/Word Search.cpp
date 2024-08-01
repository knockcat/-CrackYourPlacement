class Solution {
public:
    
    bool helper(int i, int j, int k, string& word, vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or visited[i][j] or board[i][j] != word[k])
            return false;
        
        if(k == word.size()-1)
            return true;
        
        visited[i][j] = true;
        
        bool up = helper(i-1, j, k+1, word, board, visited);
        bool left = helper(i, j-1, k+1, word, board, visited);
        bool right = helper(i, j+1, k+1, word, board, visited);
        bool down = helper(i+1, j, k+1, word, board, visited);
        
        visited[i][j] = false;
        
        return up or left or right or down;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(board[i][j] == word[0])
                {
                    if(helper(i, j, 0, word, board, visited))
                        return true;
                }
            }
        }
        
        return false;
    }
};
