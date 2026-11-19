class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int min = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < min) min = nums[i];
            m[nums[i]]++;

            if (m[nums[i]] > 1) return false;
        }


        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(min) == m.end()) {
                return false;
            } else {
                min++;
            }
        }
        return true;
    }
};
