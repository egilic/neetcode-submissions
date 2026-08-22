class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_message;
        for (string& s : strs) {
            encoded_message += to_string(s.length());
            encoded_message += '#';
            encoded_message += s;
        }
        return encoded_message;
    }

    vector<string> decode(string s) {
        cout << "printing string to decode " << s << '\n';
        vector<string> decoded_strings;
        for (auto i = 0; i < s.length();) {
            // read in the current string length
            string length_string = "";
            while (i < s.length() && s[i] != '#') {
                length_string += s[i++];
            }
            cout << "length_string is " << length_string;
            auto size = stoi(length_string) + ++i;
            string message;
            while (i < s.length() && i < size) {
                message += s[i++];
            }
            decoded_strings.push_back(message);
            cout << "iteration complete. checking index " << i << '\n';
        }
        return decoded_strings;
    }
};
