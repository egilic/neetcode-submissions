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
    int numGoodNodes = 0;
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        
        numGoodNodes++; // plus 1 for the root

        dfs(root->left,  root->val);
        dfs(root->right, root->val);

        return numGoodNodes;
    }

    void dfs(TreeNode* node, int maxSeen)
    {
        if (!node) return;

        if (node->val >= maxSeen)
        {
            numGoodNodes++;
        }

        dfs(node->left,  max(maxSeen, node->val));
        dfs(node->right, max(maxSeen, node->val));
    }
};
