class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) { return min(cost[0], cost[1]); }

        vector<int> memo(cost.size() + 1, 0);
        memo[0] = cost[0];
        memo[1] = cost[1];

        for (int n = 2; n < cost.size(); ++n) {
            memo[n] = min(memo[n-1], memo[n-2]) + cost[n];
        }
        return min(memo[cost.size()-1], memo[cost.size()-2]);
    }
};
