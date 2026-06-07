class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map vector values to indices that hold the values
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            int cur = nums[i];
            int valToFind = target - cur;
            cout << "valToFind is " << valToFind << " for cur " << cur << "\n";
            if (mp.find(valToFind) != mp.end())
            {
                // Solution found; ensure indices not the same
                vector<int>& v = mp[valToFind];
                for (int j = 0; j < v.size(); ++j)
                {
                    if (v[j] != i)
                    {
                        int _min = min(i, v[j]);
                        int _max = max(i, v[j]);
                        return {_min, _max};
                    }
                }
            }
        }

        return {};
    }
};
