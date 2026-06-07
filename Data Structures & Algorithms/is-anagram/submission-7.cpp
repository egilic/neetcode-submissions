class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vOne(26, 0);
        vector<int> vTwo(26, 0);
        for (int i = 0; i < s.length(); ++i)
        {
            vOne[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); ++i)
        {
            vTwo[t[i] - 'a']++;
        }
        return vOne == vTwo;
    }
};
