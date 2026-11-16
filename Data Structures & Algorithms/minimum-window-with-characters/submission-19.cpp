class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) { return ""; }

        int l = 0, r, matches = 0, needed = t.length(), min_window_sz = INT_MAX;
        unordered_map<char, int> substr_map; // Keep track of the charFrequency for our current substring
        unordered_map<char, int> t_map;      // Keep track of all the elements in t
        string min_substr;                   // Return value

        // Update the number of matches we need for each character 
        for (int i = 0; i < t.length(); ++i) {
            t_map[t[i]]++;
        }

        // Initialize the window

        for (r = 0 ; r <= s.length(); ++r) {
            // Update minimum window if possible
            int window_len = r - l;
            if (window_len < min_window_sz && matches == needed) {
                string tmp(s.data() + l, window_len);
                min_substr    = tmp;
                min_window_sz = window_len;
            }

            // NOTE: Should this be 'l <= r'?
            // Shrink the current window if possible
            while (matches == needed && l < r && window_len > t.length()) {
                // cout << "Shrinking at l = " << l << "\n";
                char leftChar = s[l];

                // Remove this element from the current substring of s
                substr_map[leftChar]--;

                if (t_map[leftChar] > 0 && substr_map[leftChar] < t_map[leftChar]) {
                    // Before we decrement matches, ensure we save the smallest size
                    int window_len = r - l;
                    if (window_len < min_window_sz && matches == needed) {
                        string tmp(s.data() + l, window_len);
                        min_substr    = tmp;
                        min_window_sz = window_len;
                    }
                    matches -= t_map[leftChar];
                }
                l++;
            } 

            if (r == s.length()) { break; }

            // Expand the window
            char curChar = s[r];
            substr_map[curChar]++;

            // Check for match
            // cout << "t_map frequency is " << t_map[curChar] << "\n";
            // cout << "substr_map frequency is " << substr_map[curChar] << "\n";
            if (t_map[curChar] == substr_map[curChar]) {
                // cout << "Match!\n";
                matches += t_map[curChar];
            }
        }
        return min_substr;
    }
};
