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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);

        vector<int> r;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* cur = q.front();
                q.pop();

                // Push children
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);

                if (i == size - 1)
                {
                    // This is the right most element
                    r.push_back(cur->val);
                }
            }
        }
        return r;
    }
};
