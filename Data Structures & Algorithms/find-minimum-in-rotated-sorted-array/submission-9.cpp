class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1, m, min = INT_MAX;

        // First find deflection point where element to the left is greater and element to the right is greater
        while (l < r)
        {
            m = (l + r) / 2;

            if (nums[m] > nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        m = (l + r) / 2;
        return nums[l];
    }
};

// 4 5 0 
// 