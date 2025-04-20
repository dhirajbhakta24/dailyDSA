class Solution {
    public:
        int m, n;
        string word;
        vector<vector<char>> board;
        vector<vector<bool>> visited;
    
        bool traverse(int i, int j, int idx) {
            /* accept onlt if the all the digits matched until now */
            if (i >= m or j >= n)
                return false;
            if (i < 0 or j < 0)
                return false;
            if (visited[i][j])
                return false;
            if (board[i][j] != word[idx])
                return false;
            
            /* accept only if the all the characters matched until now */
            if (idx == word.size() - 1)
                return true;
    
            visited[i][j] = true;
            bool north = traverse(i - 1, j, idx + 1);
            bool south = traverse(i + 1, j, idx + 1);
            bool west = traverse(i, j - 1, idx + 1);
            bool east = traverse(i, j + 1, idx + 1);
            visited[i][j] = false;
    
            return north || south || east || west;
        }
    
        bool exist(vector<vector<char>>& board, string word) {
            m = board.size();
            n = board[0].size();
            visited = vector<vector<bool>> (m, vector<bool>(n, false));
            this->board = board;
            this->word = word;
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (traverse(i, j, 0))
                        return true;
                }
            }
    
            return false;
        }
    };