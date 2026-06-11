class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int m = nums[0];

        while (l < r)
        {
            int mid = (l + r) / 2;

            if (mid != 0 && nums[mid] > nums[mid - 1] && nums[mid] < nums[r])
            {
                // its on the left
                r = mid - 1;
                m = min(m, nums[r]);
            }
            else
            {
                l = mid + 1;
                m = min(m, nums[l]);
            }
            m = min(m, nums[mid]);
        }



        return m;
    }
};
