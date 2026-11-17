class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, sum = 0, min_len = INT_MAX;

        while (r < nums.size()) {

            // Increment r
            sum += nums[r++];
            // cout << "Iteration r = " << r << "\n";
            int window_len = r - l;
            if (sum >= target && window_len < min_len) {
                // cout << "sum = " << sum << "\n";
                // cout << "Min found #1\n";
                // cout << "window_len = " << window_len << "\n";
                min_len = window_len;
            }

            while (sum >= target && l < r) {
                // Try to shrink the interval
                // cout << "Shrinking interval\n";
                l++;
                sum -= nums[l-1];
                window_len = r - l;

                // cout << "r = " << r << " and l = " << l << "\n";
                // cout << "window_len = " << window_len << "\n";
                // cout << "sum = " << sum << "\n";

                if (sum >= target && window_len < min_len) {
                    // cout << "Min found #2\n";

                    min_len = window_len;
                }
                // cout << "l = " << l << " and r = " << r << " and sum = " << sum << "\n";
            }
        }
        if (min_len == INT_MAX) return 0;
        return min_len;
    }
};