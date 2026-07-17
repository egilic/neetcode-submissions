class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<bool> chosen(nums.size(), false);

        for (int i = 0; i < nums.size(); ++i)
        {
            chosen[i] = true;
            vector<int> c;
            c.push_back(nums[i]);
            recurse(ans, nums, c, chosen);
            chosen[i] = false;
            c.pop_back();
        }
        return ans;
    }

    void recurse(vector<vector<int>>& ans, vector<int>& nums, vector<int> cur, vector<bool> chosen)
    {
        // Base case
        if (cur.size() == nums.size())
        {
            ans.push_back(cur);
            return;
        }



        // Either add the current element or skip
        for (int i = 0; i < chosen.size(); ++i)
        {
            // For each element either add it or skip
            if (!chosen[i])
            {
                chosen[i] = true;
                cur.push_back(nums[i]);
                recurse(ans, nums, cur, chosen);
                chosen[i] = false;
                cur.pop_back();
            }
        }
    }
};
