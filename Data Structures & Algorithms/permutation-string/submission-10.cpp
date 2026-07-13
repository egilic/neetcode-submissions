class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) { return false; }

        vector<int> vOne(26, 0);
        vector<int> vTwo(26, 0);
        for (int i = 0; i < s1.length(); ++i)
        {
            vOne[s1[i] - 'a']++;
            vTwo[s2[i] - 'a']++;
        }

        int numMatches = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (vOne[i] == vTwo[i])
            {
                numMatches++;
            }
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); ++r)
        {
            if (numMatches == 26) { return true; }

            // Analyze right pointer
            int index = s2[r] - 'a';
            vTwo[index]++;
            // Used to match
            if (vOne[index] == vTwo[index] - 1)
            {
                numMatches--;
            }
            // Now match
            else if (vOne[index] == vTwo[index])
            {
                numMatches++;
            }

            // Analyze left pointer
            index = s2[l] - 'a';
            vTwo[index]--;
            // Used to match
            if (vOne[index] == vTwo[index] + 1)
            {
                numMatches--;
            }
            // Now matchj
            else if (vOne[index] == vTwo[index])
            {
                numMatches++;
            }
            l++;
        }

        return numMatches == 26;
    }
};
