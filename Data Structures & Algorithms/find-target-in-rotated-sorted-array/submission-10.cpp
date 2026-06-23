class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), m;
        int l = 0, r = n - 1;

        while (l < r)
        {
            m = (l + r) / 2;

            // Pivot is to the right
            if ((nums[m] > nums[r] && (target > nums[m] || target <= nums[r])) || (target > nums[m] && target <= nums[r]))
            {
                cout << "l = m + 1\n";
                l = m + 1;
            }
            else
            {
                cout << "r = m\n";
                r = m;
            }
        }

        if (nums[r] == target)
        {
            return r;
        }
        return -1;
    }
};
