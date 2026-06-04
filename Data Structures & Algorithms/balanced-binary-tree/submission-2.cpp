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
    int depth(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        int maxDepth = max(depth(root->left), depth(root->right));
        return 1 + maxDepth;
    }

    bool isBalanced(TreeNode* root) {
        // base case; null is always balanced
        if (!root)
        {
            return true;
        }

        // check left and right subtrees
        bool leftIsBalanced = isBalanced(root->left);
        bool rightIsBalanced = isBalanced(root->right);
        if (!leftIsBalanced || !rightIsBalanced)
        {
            return false;
        } 

        int left = depth(root->left);
        int right = depth(root->right);
        int diff = abs(left - right);
        if (diff > 1)
        {
            return false;
        }

        return true;
    }
};
