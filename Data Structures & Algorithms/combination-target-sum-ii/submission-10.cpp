class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        dfs(ans, candidates, {}, 0, 0, target);
        return ans;
    }   

    void dfs(vector<vector<int>>& ans, vector<int>& candidates, vector<int> cur, int sum, int i, int target)
    {
        // Check for valid combination
        if (sum == target)
        {
            ans.push_back(cur);
            return;
        }

        // End dfs if sum is surpassed or invalid index
        if (sum > target || i >= candidates.size())
        {
            return;
        }

        // Add an element
        cur.push_back(candidates[i]);
        dfs(ans, candidates, cur, sum + candidates[i], i + 1, target);
        cur.pop_back();

        // Skip duplicates
        while (i < candidates.size() - 1 && candidates[i] == candidates[i+1]) { i++; }

        // Recurse
        dfs(ans, candidates, cur, sum, i + 1, target);

    }
};
