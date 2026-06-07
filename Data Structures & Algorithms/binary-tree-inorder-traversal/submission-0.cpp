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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> r;

        // Left
        vector<int> t1 = inorderTraversal(root->left);
        for (auto i : t1)
        {
            r.push_back(i);
        }
        // Parent
        r.push_back(root->val);
        // Right
        vector<int> t2 = inorderTraversal(root->right);
        for (auto i : t2)
        {
            r.push_back(i);
        }

        return r;
    }
};