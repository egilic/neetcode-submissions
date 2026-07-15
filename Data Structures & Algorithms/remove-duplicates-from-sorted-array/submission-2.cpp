class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 1;
        int res = 0;
        while (r < nums.size())
        {
            if (nums[l] > nums[r]) { r++; };
            if (nums[l] == nums[r])
            {
                // Keep extending r until we find a new element
                r++;
            }
            else
            {
                nums[l+1] = nums[r];
                l++;
                r = r + 1;
                res++;
            }
        }
        return res + 1;
    }
};