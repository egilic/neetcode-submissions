class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int numIters = INT_MAX;
        for (int i = 0; i < strs.size(); ++i)
        {
            if (strs[i].length() < numIters) numIters = strs[i].length();
        }

        string longestPrefix = "";
        for (int i = 0; i < numIters; ++i)
        {
            char matchChar;
            for (int j = 0; j < strs.size(); ++j)
            {
                if (j == 0) 
                {
                    matchChar = strs[j][i];
                }
                else if (matchChar != strs[j][i]) 
                {
                    return longestPrefix;
                }
            }
            longestPrefix += matchChar;
        }
        return longestPrefix;
    }
};