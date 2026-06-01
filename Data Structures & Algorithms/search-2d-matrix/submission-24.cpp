class Solution {
public:
    // NOTE: don't forget log(m) + log(n) = log(m*n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size(), rows = matrix.size();

        // identify which row it is in
        int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
        int foundRow = 0;
        while (top <= bottom)
        {
            int m = (top + bottom) / 2;

            if (target >= matrix[m][0] && target <= matrix[m][right])
            {
                foundRow = m;
                break;
            } else if (target < matrix[m][0])
            {
                bottom = m - 1;
            }
            else
            {
                top = m + 1;
            }
        } 

        while (left <= right)
        {
            int m = (right + left) / 2;

            if (target == matrix[foundRow][m])
            {
                return true;
            }
            else if (matrix[foundRow][m] > target)
            {
                // must be on the left
                right = --m;
            }
            else 
            {
                left = ++m;
            }
        } 

        return false;
    }
};
