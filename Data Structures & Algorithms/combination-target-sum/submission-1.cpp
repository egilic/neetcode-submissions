class Solution {
public:
    vector<vector<int>> comb;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> c;
        dfs(c, nums, target, 0, 0);
        return comb;
    }

    void dfs(vector<int>& cur, vector<int>& nums, int target, int idx, int sum) {
        // If sum is met, add it and return
        if (target == sum)
        {
            comb.push_back(cur);
            return;
        }
        if (idx >= nums.size() || sum > target) { return; }

        cur.push_back(nums[idx]);
        sum += nums[idx];
        dfs(cur, nums, target, idx, sum);

        // Dfs returned here either because the element didn't work or it worked
        cur.pop_back();
        sum -= nums[idx];
        dfs(cur, nums, target, idx + 1, sum);
    }
};
