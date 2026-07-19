class Solution {
public:
    bool isPally(string& c)
    {
        if (c.empty()) { return false; }

        int l = 0;
        int r = c.length() - 1;
        while (l <= r)
        {
            if (c[l] != c[r])
            {
                return false;
            }
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> palSubstrings;
        dfs(ans, palSubstrings, s, 0, 0);
        return ans;
    }

    void dfs(vector<vector<string>>& ans, vector<string> palSubstrings, string& s, int charsParsed, int i)
    {
        // Base case
        if (charsParsed == s.length()) 
        { 
            ans.push_back(palSubstrings); 
            return;
        }

        // Find all different permutations starting at i
        string b = "";
        for (int j = i; j < s.length(); ++j)
        {
            b.push_back(s[j]);
            if (isPally(b))
            {
                // Recurse on this
                palSubstrings.push_back(b);
                dfs(ans, palSubstrings, s, charsParsed + b.length(), j + 1);
                palSubstrings.pop_back();
            }
        }
    }
};
