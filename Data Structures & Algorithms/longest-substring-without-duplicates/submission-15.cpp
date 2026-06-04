class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.length(), len = 0, maxLen = 0;
        unordered_map<char, int> mp;

        while (r < n)
        {
            if (mp.contains(s[r]))
            {
                // character already seen; reset substring
                l = max(l, mp[s[r]] + 1);
                r = l;
                mp.clear();
                len = 0;
            } else {
                // character never seen before
                mp[s[r]] = r;
                len++;
                // BUG: make sure to save maxLen here
                maxLen = max(maxLen, len);
                r++;
            }
        }

        return maxLen;
    }
};
