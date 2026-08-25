class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp;
        dp.resize(text2.length() + 1, vector<int>(text1.length() + 1, 0));

        for (int i = text2.length() - 1; i >= 0; --i) {
            for (int j = text1.length() - 1; j >= 0; --j) {
                if (text2[i] == text1[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
