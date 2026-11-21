class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valIndexMap;

        for (int i = 0; i < nums.size(); ++i) {
            valIndexMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int dif = target - nums[i];
            if (valIndexMap.find(dif) != valIndexMap.end() && valIndexMap[dif] != i) {
                return {i, valIndexMap[dif]};
            }
        }
        return {};
    }
};
