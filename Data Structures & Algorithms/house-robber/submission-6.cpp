class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[1], nums[0]);
        }

        vector<int> cache(nums.size() + 1, 0);
        cache[0] = nums[0];
        cache[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            cache[i] = max(cache[i-1], cache[i-2] + nums[i]);
        }

        return cache[nums.size() -1];
    }
};
