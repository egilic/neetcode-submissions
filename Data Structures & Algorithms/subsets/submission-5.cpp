class Solution {
public:
    vector<vector<int>> sets;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> c;
        dfs(c, nums, 0);
        return sets;
    }

    void dfs(vector<int>& cur, vector<int>& nums, int idx)
    {
        if (idx >= nums.size()) { 
            sets.push_back(cur);
            return; 
        }

        cur.push_back(nums[idx]);
        dfs(cur, nums, idx + 1);

        cur.pop_back();
        dfs(cur, nums, idx + 1);
    }
};
