class Solution {
public:
    vector<vector<int>> res;
    vector<int> nums;
    int targ;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        targ = target;
        sort(candidates.begin(), candidates.end());
        nums = candidates;
        dfs(0, {}, 0);
        
        return res;
    }

    void dfs(int i, vector<int> cur, int sum)
    {
        if (sum == targ)
        {
            res.push_back(cur);
            return;
        }
        if (i >= nums.size() || sum > targ)
        {
            return;
        }

        // recurse
        for (int j = i; j < nums.size(); ++j)
        {
      
            if (j > i && nums[j] == nums[j-1]) continue;
            cur.push_back(nums[j]);
            dfs(j + 1, cur, sum + nums[j]);
            cur.pop_back();
        }
    }


};
