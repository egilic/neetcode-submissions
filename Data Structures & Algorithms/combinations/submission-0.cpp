class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        dfs(ans, n, k, 1, {});
        return ans;
    }

    void dfs(vector<vector<int>>& ans, int n, int k, int curIndex, vector<int> cur)
    {
        // We either include the number at current or do not
        if (cur.size() == k)
        {
            ans.push_back(cur);
            return;
        }
        if (curIndex > n)
        {
            return;
        }

        cur.push_back(curIndex);
        dfs(ans, n, k, curIndex + 1, cur);
        cur.pop_back();
        dfs(ans, n, k, curIndex + 1, cur);
    }
};