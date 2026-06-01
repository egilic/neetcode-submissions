class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, u = 0, r = matrix[0].size() - 1, d = matrix.size() - 1;
        int mid;
        char lastUpdated;
    
        while(u <= d){
            mid = (d + u) / 2;
            if(target == matrix[mid][0]){
                return true;
            }
            else if(target < matrix[mid][0]){
                d = mid - 1;
            }
            else{
                u = mid + 1;
            }
        }
        if (d < 0) return false;
        while(l <= r){
            mid = (l + r) / 2;
            if(target == matrix[d][mid]){
                return true;
            }
            else if(target < matrix[d][mid]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};
