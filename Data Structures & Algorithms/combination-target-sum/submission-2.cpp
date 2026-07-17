class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        dfs(ans, nums, {}, target, 0, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int> cur, int target, int i, int sum)
    {
        if (sum == target)
        {
            ans.push_back(cur);
            return;
        }
        if (sum > target || i >= nums.size())
        {
            return;
        }

        cur.push_back(nums[i]);
        dfs(ans, nums, cur, target, i, sum + nums[i]);
        cur.pop_back();

        dfs(ans, nums, cur, target, i + 1, sum);
    }
};
