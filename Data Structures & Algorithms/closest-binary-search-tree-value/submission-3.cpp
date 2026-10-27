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
    int closestValue(TreeNode* root, double target) {
        queue<TreeNode*> q;
        if (root) { q.push(root); }
        double diff = INT_MAX;
        double closest = 0;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; ++i) {
                TreeNode* n = q.front(); 
                q.pop();

                if (n->left) { q.push(n->left); }
                if (n->right) { q.push(n->right); }

                if (abs(n->val - target) < diff) {
                    diff = abs(static_cast<double>(n->val) - target);
                    closest = static_cast<double>(n->val);
                }
            }
        }
        return closest;
    }
};
