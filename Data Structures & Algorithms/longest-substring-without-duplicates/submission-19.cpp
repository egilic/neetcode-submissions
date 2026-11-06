class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;
        unordered_map<char, int> charFreq;
        charFreq[s[0]] = 1;

        int l = 0, r = 1;
        int maxLen = 0;

        while (r < s.length()) {
            char curChar = s[r];
            // Update max
            if (r - l > maxLen) {
                maxLen = r - l;
            }

            // Non unique substring move left until it's unique
            if (charFreq[curChar] >= 1) {
                while (charFreq[curChar] >= 1) {
                    char lChar = s[l];
                    charFreq[lChar]--;
                    l++;
                }
            }

            charFreq[curChar]++;
            // Update max
            if (r - l > maxLen) {
                maxLen = r - l;
            }

            r++;
        }
        if (r - l > maxLen) {
            maxLen = r - l;
        }
        return maxLen;
    }
};
