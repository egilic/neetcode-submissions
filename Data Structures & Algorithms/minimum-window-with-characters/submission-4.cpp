class Solution {
public:
    string minWindow(string s, string t) {
        /* Using to verify valid substring */
        int cur_matches = 0, need = 0, l = 0;

        unordered_map<char, int> t_map;
        for (int i = 0; i < t.length(); ++i) {
            t_map[t[i]]++;
        }
        need = t_map.size();

        /* Use to keep track of where the shortest substring is for return */
        int substring_len = INT_MAX, substring_index = 0;

        unordered_map<char, int> substring_map;

        for (int r = 0; r < s.length(); ++r) {
            char c = s[r];

            /* If t contains this element, this might be promising */
            if (t_map.contains(c)) {
                /* This is a new match */
                if (substring_map[c] + 1 == t_map[c]) {
                    cur_matches++;
                }
                substring_map[c]++;
            }
 
            /* Try to shrink the substring */
            while (need == cur_matches) {
                int cur_substr_len = r - l + 1;
                if (cur_substr_len < substring_len) {
                    substring_len = cur_substr_len, substring_index = l;
                }

            
                char l_char = s[l];
                if (substring_map[l_char] > 0) {
                    substring_map[l_char]--;
                    if (substring_map[l_char] < t_map[l_char]) {
                        cur_matches--;
                    }
                }
                l++;
        
            }   
        }
        if (substring_len == INT_MAX) {
            return "";
        }
        cout << "index is " << substring_index << " and length is " << substring_len << "\n";
        string r(s.data() + substring_index, substring_len);
        return r;
    }
};
