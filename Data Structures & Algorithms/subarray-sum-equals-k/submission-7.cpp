class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int runningTotal = 0;
        int numSubarrays = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            runningTotal += nums[i];

            int diff = k - runningTotal;
            int wantedKey = diff * -1;

            if (mp.contains(wantedKey))
            {
                numSubarrays += mp[wantedKey];
            }

            // Add current running sum to the map
            mp[runningTotal]++;
        }

        return numSubarrays;
    }
};