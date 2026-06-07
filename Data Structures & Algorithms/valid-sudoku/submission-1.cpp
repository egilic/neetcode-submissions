class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows;
        vector<unordered_set<char>> cols;
        vector<unordered_set<char>> boxs;
        rows.resize(9);
        cols.resize(9);
        boxs.resize(9);

        int r = board.size(), c = board[0].size();

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                char c = board[i][j];
                if (c == '.') continue;

                int boxIndex = 3*(i / 3) + (j / 3);
                if (rows[i].count(c) || cols[j].count(c) || boxs[boxIndex].count(c))
                {
                    return false;
                }
                else
                {
                    rows[i].insert(c);
                    cols[j].insert(c);
                    boxs[boxIndex].insert(c);
                }
            }
        }
        return true;
    }
};
