class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Swap rows
        int top = 0, bottom = rows - 1;
        while (top < bottom) {
            for (int c = 0; c < cols; ++c) {
                int tmp = matrix[top][c];
                matrix[top][c]    = matrix[bottom][c];
                matrix[bottom][c] = tmp;
            }
            top++;
            bottom--;
        }

        // Tranpose
        for (int r = 0; r < rows; ++r) {
            for (int c = r + 1; c < cols; ++c) {
                int tmp = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = tmp;
            }
        }
        
    }
};
