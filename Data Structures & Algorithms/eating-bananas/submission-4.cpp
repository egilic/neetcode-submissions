class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i, rightBound, leftBound = 1, n = piles.size(), minK = INT32_MAX;
        rightBound = *std::max_element(piles.begin(), piles.end());


        while (leftBound <= rightBound) 
        {
            int k = (leftBound + rightBound) / 2;
            cout << "Testing eating speed of " << k << " bananas!\n";
            int hoursElapsed = 0;
            // Can we eat all the bananas in time, given this eating speed, k
            for (i = 0; i < n; ++i)
            {
                double t = ceil(piles[i] * 1.0 / k * 1.0);
                cout << t << " ";
                double tmp = ceil(t);

                hoursElapsed += t;
            }
            cout << "\n\tIt will take " << hoursElapsed << " hours to finish all the bananas\n";

            if (hoursElapsed <= h)
            {
                cout << "Time in range\n";
                // Time limit within range; update min if applicable
                rightBound = k - 1;
                minK = min(minK, k);
            }
            else 
            {
                cout << "Time out of range\n";
                // Time limit too long
                leftBound = k + 1;
            }
        }

        return minK;
    }
};
