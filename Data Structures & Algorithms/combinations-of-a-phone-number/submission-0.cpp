class Solution {
public:
    string returnChars(int val)
    {
        if (val == 2)
        {
            return "abc";
        }
        else if (val == 3)
        {
            return "def";
        }
        else if (val == 4)
        {
            return "ghi";
        }
        else if (val == 5)
        {
            return "jkl";
        }
        else if (val == 6)
        {
            return "mno";
        }
        else if (val == 7)
        {
            return "pqrs";
        }
        else if (val == 8)
        {
            return "tuv";
        }
        else
        {
            return "wxyz";
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) return ans;
        dfs(ans, digits.length(), "", 0, digits);
        return ans;
    }

    void dfs(vector<string>& ans, int comboLen, string cur, int i, string& digits)
    {
        if (cur.length() == digits.length())
        {
            ans.push_back(cur);
            return;
        }

        int val = digits[i] - '0';
        string letters = returnChars(val);

        for (int j = 0; j < letters.length(); ++j)
        {
            cur.push_back(letters[j]);
            dfs(ans, comboLen, cur, i + 1, digits);
            cur.pop_back();
        }
    }
};
