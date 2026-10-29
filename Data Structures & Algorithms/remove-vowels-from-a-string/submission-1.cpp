class Solution {
public:
    string removeVowels(string s) {
        string r;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a' | s[i] == 'e' |
                s[i] == 'i' | s[i] == 'o' | s[i] == 'u') {

                } else {
                    r += s[i];
                }
        }
        return r;
    }
};
