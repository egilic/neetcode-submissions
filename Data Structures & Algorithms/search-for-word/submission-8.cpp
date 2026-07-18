class Solution {
public:
    int rows;
    int cols;
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        vector<vector<bool>> visited;
        visited.resize(rows);
        for (int i = 0; i < board.size(); ++i)
        {
            visited[i].resize(cols, false);
        }

        char firstC = word[0];
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (board[i][j] == firstC)
                {
                    if (word.length() == 1) return true;
                    visited[i][j] = true;
                    bool ret = dfs(board, word, 1, i + 1, j, visited) || 
                               dfs(board, word, 1, i - 1, j, visited) ||
                               dfs(board, word, 1, i, j + 1, visited) ||
                               dfs(board, word, 1, i, j - 1, visited);
                    visited[i][j] = false;
                    if (ret) return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int index, int row, int col, vector<vector<bool>> visited)
    {
        // Ensure we are within bounds
        if (row >= rows || row < 0 || col < 0 || col >= cols)
        {
            return false;
        }

        // Check value
        if (board[row][col] != word[index] || visited[row][col]) { return false; }
        index++;
        // cout << "Streak continues at {row, col} {" << row << ", " << col << "}\n";  

        // Check if index one past the word length
        if (index == word.length())
        {
            // cout << "Returning true at row/col " << row << ", " << col << endl;
            return true;
        }

        // cout << "Solution not reached and valid indices, checking if board[row][col] == word[index]\n";
        // cout << "Does " << board[row][col] << " == " << word[index] << "?\n";

        visited[row][col] = true;

        // Recurse
        return dfs(board, word, index, row - 1, col, visited) || dfs(board, word, index, row + 1, col, visited) ||
               dfs(board, word, index, row, col + 1, visited) || dfs(board, word, index, row, col - 1, visited);
    }
};
