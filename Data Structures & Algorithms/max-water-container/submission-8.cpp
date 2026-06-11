class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int width = r;
        int maxArea = 0;

        while (l < r)
        {
            int _m = min(heights[l], heights[r]);
            int area = _m * width;
            maxArea = max(maxArea, area);

            if (heights[l] < heights[r])
            {
                l++;
            }
            else 
            {
                r--;
            }


            width--;
        }

        return maxArea;
    }
};
