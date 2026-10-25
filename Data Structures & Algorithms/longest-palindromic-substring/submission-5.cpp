class Solution {
public:
    string longestPalindrome(string s) {
        string r_str;

        for (int i = 0; i < s.length(); ++i) {
            // odd case
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > r_str.length()) {
                    string longest_s(s, l, r - l + 1);
                    r_str = longest_s;
                }
                l--; r++;
            }


            // even case
            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > r_str.length()) {
                    string longest_s(s, l, r - l + 1);
                    r_str = longest_s;
                }
                l--; r++;
            }
        }

        return r_str;
    }
};
