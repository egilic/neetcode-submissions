class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;


        while (l < r)
        {
            if (s[l] != s[r])
            {
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(string& s, int i, int j)
    {
        int l = i;
        int r = j;
        while (l < r)
        {
            if (s[l++] != s[r--]) 
            {
                return false;
            }
        }
        return true;
    }
};