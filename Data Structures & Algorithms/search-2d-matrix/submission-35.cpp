class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int r_idx = 0;
        for (int r = 0; r < rows; ++r) {
            if (target <= matrix[r][cols-1]) {
                r_idx = r;
                break;
            }
        }

        int l = 0, r = cols - 1;
        int c_idx = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            cout << "mid=" << mid << "\n";
            if (matrix[r_idx][mid] > target) {
                r = mid - 1;
            } else if (matrix[r_idx][mid] < target) {
                l = mid + 1;
            } else {
                c_idx = mid;
                break;
            }
        }

        cout << "c_idx=" << c_idx;
        cout << "\nr_idx=" << r_idx;
        return c_idx != INT_MAX;
    }
};
