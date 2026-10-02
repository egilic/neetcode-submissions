class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size(), -1);
        return findMaxMoney(nums, cache, 0);
    }

    int findMaxMoney(vector<int>& nums, vector<int>& cache, int j) {
        if (j >= nums.size()) { return 0; }
        if (cache[j] != -1) { return cache[j]; }
        int rob  = nums[j] + findMaxMoney(nums, cache, j + 2);
        int skip = findMaxMoney(nums, cache, j + 1);
        return cache[j] = max(rob, skip);
    }
};
