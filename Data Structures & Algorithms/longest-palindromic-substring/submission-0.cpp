class Solution {
public:
    string longestPalindrome(string s) {
        /* iterate and use each character as the middle */
        int res_index = 0, res_len = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int left = i - 1;
            int right = i + 1;
            
            int odd_start = i;
            int odd_len = check(s, left, right, odd_start);

            int even_left_start = left;
            int even_left_len = check(s, left, i, even_left_start);

            int even_right_start = i;
            int even_right_len = check(s, i, right, even_right_start);

            res_len = max({res_len, odd_len, even_left_len, even_right_len});
            if (odd_len == res_len) {
                res_index = odd_start;
            } else if (even_left_len == res_len) {
                res_index = even_left_start;
            } else if (even_right_len == res_len) {
                res_index = even_right_start;
            }
        }
        cout << res_index << " is res_index and len is " << res_len << "\n";
        string ret(s.data() + res_index, res_len);
        return ret;
    }

    int check(string s, int l, int r, int& start_index) {
        while (l >= 0 && r <= s.length() - 1) {
            if (s[l] != s[r]) {
                break;
            } else {
                start_index = l;
                l--;
                r++;
            }
        }
        return r - l - 1;
    }

};
