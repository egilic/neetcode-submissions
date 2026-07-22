class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0; 
        for (int i = 0; i < height.size(); ++i)
        {
            // No water trapped on corners
            if (i == 0 || i == height.size() - 1) { continue; }

            int greatestLeft = height[i], greatestRight = height[i];
            int leftIndex = 0, rightIndex = 0;
            for (int j = 0; j < height.size(); ++j)
            {
                // Values to the left of our current index
                if (j < i)
                {   
                    if (height[j] > greatestLeft)
                    {
                        greatestLeft = height[j];
                        leftIndex = j;
                    }
                }

                // Values to the right of our current index
                if (j > i)
                {
                    if (height[j] > greatestRight)
                    {
                        greatestRight = height[j];
                        rightIndex = j;
                    }
                }
            }

            if (greatestLeft != height[i] && greatestRight != height[i])
            {
                // Two elements greater on each side
                int trappedWater = min(height[leftIndex], height[rightIndex]) - height[i];
                total += trappedWater;
            }   
        }
        return total;
    }
};
