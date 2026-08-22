class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(helper(vector<int>(nums.begin() + 1, nums.end())), 
                   helper(vector<int>(nums.begin(), nums.end() - 1)));
    }

    int helper(vector<int> vec) {
        if (vec.empty()) return 0;
        if (vec.size() == 1) return vec[0];

        vector<int> cache(vec.size());
        cache[0] = vec[0];
        cache[1] = max(vec[0], vec[1]);
        for (int i = 2; i < vec.size(); ++i) {
            cache[i] = max(vec[i] + cache[i-2], cache[i-1]);
        }
        return cache[vec.size() - 1];
    }
};
