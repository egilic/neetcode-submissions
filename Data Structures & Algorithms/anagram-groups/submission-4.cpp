class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int NUM_LETTERS = 26;
        map<vector<int>, vector<string>> string_map;


        // Loop through all strings
        for (int i = 0; i < strs.size(); ++i) {
            // Initialize vector of each character and how often they occur to use as key
            vector<int> char_occurences(NUM_LETTERS, 0);
            for (int j = 0; j < strs[i].size(); ++j) {
                size_t index = strs[i][j] - 'a';
                char_occurences[index]++;
            }

            // Update map entry
            string_map[char_occurences].push_back(strs[i]);
        }

        // Loop through the map and move each original string to an element in the vector
        vector<vector<string>> ret;
        for (const auto& elem : string_map) {
            ret.push_back(elem.second);
        }

        return ret;
    }
};
