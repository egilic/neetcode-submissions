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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
        {
            return {};
        }

        vector<int> v;
        v.push_back(root->val);
        vector<int> t1 = preorderTraversal(root->left);
        vector<int> t2 = preorderTraversal(root->right);
        for (auto& t : t1)
        {
            v.push_back(t);
        }
        for (auto& t : t2)
        {
            v.push_back(t);
        }
        return v;
    }
};