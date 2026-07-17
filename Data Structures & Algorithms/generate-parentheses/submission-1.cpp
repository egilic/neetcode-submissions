class Solution {
public:
    int n;

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        this->n = n;

        dfs(ans, "", 0, 0);

        return ans;
    }

    void dfs(vector<string>& ans, string cur, int numOpen, int numClosed)
    {
        // Base case
        if (numOpen + numClosed == n * 2)
        {
            ans.push_back(cur);
            return;
        }

        if (numOpen == numClosed)
        {
            // Must start with an open parentheses
            cur.push_back('(');
            numOpen++;
            dfs(ans, cur, numOpen, numClosed);
        }
        else
        {
            // Closed case first
            cur.push_back(')');
            numClosed++;
            dfs(ans, cur, numOpen, numClosed);

            if (numOpen != n)
            {
                // Can add more open
                cur.pop_back();
                numClosed--;

                cur.push_back('(');
                numOpen++;
                dfs(ans, cur, numOpen, numClosed);
            }
        }
    }
};
