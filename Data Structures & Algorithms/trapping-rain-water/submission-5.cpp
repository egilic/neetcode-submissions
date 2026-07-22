class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, total = 0;
        int leftMax = height[l], rightMax = height[r];

        while (l < r)
        {
            if (leftMax < rightMax)
            {
                l++;
                int waterTrapped = min(leftMax, rightMax) - height[l];
                if (waterTrapped > 0) total += waterTrapped;
                if (height[l] > leftMax) { leftMax = height[l]; }
                
            }
            else
            {
                r--;
                int waterTrapped = min(leftMax, rightMax) - height[r];
                if (waterTrapped > 0) total += waterTrapped;
                if (height[r] > rightMax) { rightMax = height[r]; }
            }
        }
        return total;
    }
};
