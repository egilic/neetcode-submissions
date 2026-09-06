class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        return check(nums, sum, 0, 0);
    }

    bool check(vector<int>& og_nums, int l_sum, int r_sum, int index) {
        if (l_sum == r_sum) {
            return true;
        }

        if (index >= og_nums.size()) {
            return false;
        }

        /* Add element at index to the right vector */ 
        if (check(og_nums, l_sum - og_nums[index], r_sum + og_nums[index], index + 1)) {
            return true;
        }

        if (check(og_nums, l_sum, r_sum, index + 1)) {
            return true;
        }

        return false;
    }
};
