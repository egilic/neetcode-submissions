class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> charFreq;
        for (int i = 0; i < s1.length(); ++i) { charFreq[s1[i]]++; }
        int i = 0;
        int anchor = 0;

        unordered_map<char, int> mpCopy = charFreq;
        while (i < s2.length())
        {
            // Check current char's existence
            char c = s2[i];
            if (mpCopy.contains(c))
            {
                mpCopy[c]--;
                if (mpCopy[c] == 0) 
                {
                    mpCopy.erase(c); 
                }
                i++;
            }
            else
            {
                cout << "Resetting the map on iteration i = " << i << endl;
                // Reset map
                mpCopy = charFreq;
                anchor++;
                i = anchor;
                // Don't increment r if original map contains it; could make another valid sequence
                // starting at this char
                if (!mpCopy.contains(c))
                {
                    i++;
                }
            }
            if (mpCopy.empty()) { return true; }
        }
        return false;
    }
};
