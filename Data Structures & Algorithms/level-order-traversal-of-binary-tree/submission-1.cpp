/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);

        vector<vector<int>> r;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> inner(size);
            for (int i = 0; i < size; ++i)
            {
                TreeNode* c = q.front();
                q.pop();

                inner[i] = c->val;

                // Also push back children in the order {left, right}
                if (c->left)  q.push(c->left);
                if (c->right) q.push(c->right);
            }
            r.push_back(inner);
        }
        return r;
    }
};
