class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.length() < s.length()) { return false; }
        int sPtr = 0, tPtr = 0;

        while (sPtr < s.length() && tPtr < t.length()) {
            if (s[sPtr] == t[tPtr]) {
                sPtr++;
                tPtr++;
            } else {
                tPtr++;
            }
        }
        return sPtr == s.length();
    }
};