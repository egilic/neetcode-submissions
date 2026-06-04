class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.length(), len = 0, maxLen = 0;
        unordered_set<char> cSet;

        while (r < n)
        {
            if (cSet.find(s[r]) != cSet.end())
            {
                // character already seen; reset substring
                cSet.clear();
                l++;
                r = l;
                len = 0;
            } else {
                // character never seen before
                cSet.insert(s[r]);
                len++;
                // BUG: make sure to save maxLen here
                maxLen = max(maxLen, len);
                r++;
            }
        }

        return maxLen;
    }
};
