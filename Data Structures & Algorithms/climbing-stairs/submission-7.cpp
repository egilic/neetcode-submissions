class Solution {
public:
    int climbStairs(int n) {
        // top down approach
        vector<int> memo(n+1, -1);
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }
        if (memo[n] == -1) {
            memo[n] = dp(memo, n-1) + dp(memo, n-2);
        }
        return memo[n];
    }
    
    int dp(vector<int>& memo, int i) {
        if (i <= 1) {
            return 1;
        } 

        if (memo[i] == -1) {
            memo[i] = dp(memo, i-1) + dp(memo, i-2);
        }
        return memo[i];
    }
};
