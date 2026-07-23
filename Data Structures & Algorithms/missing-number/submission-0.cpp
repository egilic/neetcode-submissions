class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            total += nums[i];
        }

        int expectedTotal = 0;
        for (int i = 0; i <= nums.size(); ++i)
        {
            expectedTotal += i;
        }

        return expectedTotal - total;
    }
};
