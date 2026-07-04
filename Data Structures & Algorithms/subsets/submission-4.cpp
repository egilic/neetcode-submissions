class Solution {
public:
    vector<vector<int>> sets;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        sets.push_back({});
        vector<int> c;
        dfs(c, nums, 0);
        return sets;
    }

    void dfs(vector<int>& cur, vector<int>& nums, int idx)
    {
        if (idx >= nums.size()) { return; }


        cur.push_back(nums[idx]);
        sets.push_back(cur);

        dfs(cur, nums, idx + 1);

        cur.pop_back();
        
        dfs(cur, nums, idx + 1);
    }
};
