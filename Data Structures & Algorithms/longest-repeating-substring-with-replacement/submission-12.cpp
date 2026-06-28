class Solution {
public:
    void printSeq(string s, int l, int r)
    {
        cout << "\tSequence is ";
        while (l <= r)
        {
            cout << s[l];
            l++;
        }
        cout << endl;
    }

    void pFreq(unordered_set<char>& c, unordered_map<char, int>& m)
    {   
        auto it = c.begin();
        while (it != c.end())
        {
            cout << "\tfrequency of " << *it << " is " << m[*it] << "\n";
            ++it;
        }
    }

    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.length();
        int maxWindow = 0;
        unordered_map<char, int> cFreq;
        unordered_set<char> chars;
        chars.insert(s[0]);
        cFreq[s[0]]++;

        int iters = 0;
        while (r < n)
        {
            // cout << "==iteration " << iters++ << "==\n";
            // printSeq(s, l , r);

            // Find the character with the most occurrences
            int maxFreq = 0;
            auto it = chars.begin();
            // pFreq(chars, cFreq);
            while (it != chars.end()) { 
                maxFreq = max(maxFreq, cFreq[*it]); 
                it++;
            }

            int windowSize = r - l + 1;
            // cout << "\tDEBUG: maxFreq = " << maxFreq << endl;
            int replacementsNeeded = windowSize - maxFreq;

            if (replacementsNeeded > k)
            {
                // cout << "\treplacementsNeeded > k; " << replacementsNeeded << endl;
                char lChar = s[l];
                cFreq[lChar]--;
                l++;
                // Remove from the set if this is the last occurrence
                if (cFreq[lChar] == 0) { chars.erase(lChar); }
            }
            else
            {
                // cout << "\treplacementsNeeded <= k; " << replacementsNeeded << endl;
                // Replacement not needed
                // cout << "\tupdating longestCharReplacement to be " << maxWindow << ", " << windowSize << "\n";
                maxWindow = max(maxWindow, windowSize);
                r++;
                char c = s[r];
                chars.insert(c);
                cFreq[c]++;
            }
        }

        return maxWindow;
    }
};
