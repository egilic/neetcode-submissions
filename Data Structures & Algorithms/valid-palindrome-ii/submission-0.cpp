class Solution {
public:
    bool validPalindrome(string s) {
        if (isPalindrome(s)) return true;

        for (int i = 0; i < s.length(); ++i)
        {
            string newS = s;
            newS.erase(i, 1);
            cout << "newString is " << newS << endl;
            if (isPalindrome(newS))
            {
                cout << "Removed character at index " << i << endl;
                return true;
            }
        }
        return false;
    }
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.length() - 1;
        while (l <= r)
        {
            if (s[l++] != s[r--]) 
            {
                return false;
            }
        }
        return true;
    }
};