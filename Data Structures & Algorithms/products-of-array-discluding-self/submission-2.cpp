class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        vector<int> retVec(nums.size(), 0);

        // Populate the prefix array
        // [1, 2, 4, 6]
        // [1, 1, 2, 8]
        for (int i = 1; i < nums.size(); ++i)
        {
            if (i == 1) prefix[i] = nums[i - 1];
            else prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        // Populate the postfix array
        // [1,  2,  4, 6]
        // [48, 24, 6, 1]
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (i == nums.size() - 2) suffix[i] = nums[i + 1];
            else suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0)
                cout << prefix[i] << " " << suffix[i];
            retVec[i] = prefix[i] * suffix[i];
        }
        return retVec;
    }
};
