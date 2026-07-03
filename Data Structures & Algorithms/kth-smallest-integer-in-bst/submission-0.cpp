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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodeValues;
        dfs(nodeValues, root);
        return nodeValues[k - 1];
    }

    void dfs(vector<int>& values, TreeNode* node)
    {
        if (!node) { return; }

        dfs(values, node->left);
        values.push_back(node->val);
        dfs(values, node->right);
    }
};
