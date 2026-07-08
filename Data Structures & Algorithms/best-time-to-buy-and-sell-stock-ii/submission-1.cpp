class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) { return 0; }
        int l = 0;
        int r = 1;

        int maxProfit = 0;
        while (r < prices.size())
        {
            // Can we make a profit here?
            int profit = prices[r] - prices[l];
            if (profit > 0)
            {
                maxProfit += profit;
            }
            l++;
            r++;
        }
        return maxProfit;
    }
};