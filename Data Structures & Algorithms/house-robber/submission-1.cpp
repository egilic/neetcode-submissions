class Solution {
public:
    // top-down; build cache
    vector<int> cache;
    vector<int> house_values;


    int rob(vector<int>& nums) {
        cache.resize(nums.size(), -1);
        house_values = nums;
        int max_money = dp(nums.size() - 1);
        return max_money;
    }

    int dp(int i) {
        if (i < 0) {
            return 0;
        }
        if (i == 0) {
            return house_values[0];
        }
        if (i == 1) {
            if (house_values[0] >= house_values[1]) {
                return house_values[0];
            }
            return house_values[1];
        }

        if (cache[i] != -1) {
            return cache[i];
        }

        cache[i] = max(max(dp(i - 2), dp(i - 3)) + house_values[i], dp(i - 1));
        return cache[i];
    }
};
