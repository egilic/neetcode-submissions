class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int a = 1; a <= amount; ++a) {
            for (int c = 0; c < coins.size(); ++c) {
                int c_amt = coins[c];
                if (a - c_amt >= 0) {
                    dp[a] = min(dp[a], 1 + dp[a-c_amt]);
                }
            }
        }

        if (dp[amount] != amount + 1) return dp[amount];
        return -1;
    }
};
