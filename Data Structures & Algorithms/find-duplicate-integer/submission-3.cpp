class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 0);

        for (int i = 0; i < nums.size(); ++i)
        {
            // -1 because we are in range 1 to size of nums
            int j = nums[i] - 1;
            if (v[j] == 0)
            {
                v[j]++;
            }
            else
            {
                return nums[i];
            }
        }
        return 0;
    }
};
