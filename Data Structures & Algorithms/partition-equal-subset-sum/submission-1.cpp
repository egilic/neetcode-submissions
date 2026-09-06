class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) { sum += nums[i]; }
        if (sum % 2 == 1) { return false; }
        int target = sum / 2;

        unordered_set<int> s;
        s.insert(0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            unordered_set<int> tmp;
            auto it = s.begin();
            while (it != s.end()) {
                int val = *it;
                tmp.insert(val + nums[i]);
                tmp.insert(val);
                ++it;
            }
            s = tmp;
        }
        if (s.find(target) != s.end()) { return true; }
        return false;
    }
};
