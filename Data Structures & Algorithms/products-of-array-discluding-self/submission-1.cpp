class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), i;
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = 1;
        suffix[n-1] = 1;

        for (i = 1; i < n; ++i)
        {
            prefix[i] = prefix[i-1] * nums[i-1];
            suffix[n-1-i] = suffix[n-i] * nums[n-i]; // suffix[2] = 1 * 4, suffix[1] = 4 * 2 = 8
                                                     // suffix[0] = 8 * 
        }
        for (i = n - 1; i >= 1; --i)
        {
            suffix[i-1] = suffix[i] * nums[i]; // suffix[2] = 1 * 4 = 4, suffix[1] = 4 * 2 = 8
                                               // suffix[0] = 8 * 6 = 48
        }

        // input   : [5, 6, 2, 4]
        // prefix  : [1, 5, 30, 60]
        // sufffix : [48, 8, 4, 1] 
        vector<int> r(n);
        for (i = 0; i < n; ++i)
        {
            r[i] = prefix[i] * suffix[i];
        }

        return r;
    }
};
