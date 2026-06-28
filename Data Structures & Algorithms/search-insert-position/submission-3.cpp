class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size() - 1;

        int i = 0;
        while (l < r)
        {
            // cout << "===Iteration " << i++ << "===\n";
            // cout << "left index = " << l << "\n";
            // cout << "right index = " << r << "\n";
            int mid = (l + r) / 2;
            int midVal = nums[mid];

            if (midVal == target)
            {
                return mid;
            }
            else if (midVal > target)
            {
                // cout << "Moving right to mid - 1. index = " << mid - 1 << " value = " << nums[mid - 1] << endl;
                r = mid - 1;
            }
            else
            {
                // cout << "Moving left to mid + 1. index = " << mid + 1 << " value = " << nums[mid + 1] << endl;
                l = mid + 1;
            }
        }    

        if (nums[l] == target || nums[l] > target)
        {
            return l;
        }
        else 
        {
            // if (nums[l] < target)
            // {
            return l + 1;
            // }
        }
    }
};