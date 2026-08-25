class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t n = matrix.size(), l = 0, r = n - 1;

        while (l < r) {
            for (size_t i = 0; i < r - l; i++) {
                size_t bottom = r, top = l;
                // save the top left
                int top_left = matrix[top][l + i];

                // move the bottom left into the top left
                matrix[top][l + i] = matrix[bottom - i][l];
                
                // move the bottom right into bottom left
                matrix[bottom - i][l] = matrix[bottom][r - i];

                // move the top right into the bottom right
                matrix[bottom][r - i] = matrix[top + i][r];

                // move the top left to the top right
                matrix[top + i][r] = top_left;
            }
            l++;
            r--;
        }
    }
};
