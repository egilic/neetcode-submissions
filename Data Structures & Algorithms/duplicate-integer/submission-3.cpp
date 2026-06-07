class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums)
        {
            if (s.count(num)) return true;
            else s.insert(num);
        }
        return false;
    }
};