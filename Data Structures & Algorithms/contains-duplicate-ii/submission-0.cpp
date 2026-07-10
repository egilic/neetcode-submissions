class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); ++i) { mp[nums[i]].push_back(i); }

        for (auto& elem : mp)
        {
            if (elem.second.size() > 1) { 
                vector<int>& ref = elem.second;
                for (int i = 0; i < ref.size(); ++i)
                {
                    for (int j = 0; j < ref.size(); ++j)
                    {
                        if (i == j) { continue; }
                        if (abs(ref[i] - ref[j]) <= k) { return true; }
                    }
                }
            }
        }
        return false;
    }
};