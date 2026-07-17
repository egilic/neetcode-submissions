class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        dfs(ans, nums, {}, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int> cur, int index)
    {
        // Base case
        if (index == nums.size())
        {
            ans.push_back(cur);
            return;
        }

        // Add current element
        cur.push_back(nums[index]);
        dfs(ans, nums, cur, index + 1);
        cur.pop_back();

        // Before we recurse again; ensure we don't start recursion with a duplication
        while (index < nums.size() - 1 && nums[index] == nums[index + 1]) { index++; }
        dfs(ans, nums, cur, index + 1);
    }
};
