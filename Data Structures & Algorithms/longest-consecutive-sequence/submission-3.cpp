class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        using num = int;
        using idx = int;
        
        unordered_map<num, idx> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
            mp[nums[i]] = i;
        }

        unordered_set<int> checked;
        int longest = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (checked.find(nums[i]) != checked.end())
            {
                // Already looked at this element
                continue;
            }
            else
            {
                int curStreak = 1;
                int val = nums[i];
                checked.insert(val);
                

                while (mp.find(val - 1) != mp.end())
                {
                    val--;
                    curStreak++;
                    checked.insert(val);
                }

                val = nums[i];
                while (mp.find(val + 1) != mp.end())
                {
                    val++;
                    curStreak++;
                    checked.insert(val);
                }
                longest = max(longest, curStreak);
            }
        }
        return longest;
    }
};
