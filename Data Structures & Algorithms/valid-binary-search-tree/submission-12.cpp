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
    bool isValidBST(TreeNode* root) {
        int min = INT_MIN;
        int max = INT_MAX;

        if (!root) { return true; }

        // Go to the left tree
        return recurse(root->left, min, root->val) && recurse(root->right, root->val, max);
    }

    bool recurse(TreeNode* node, int left, int right) {
        if (!node) return true;

        if (node->val > left && node->val < right) {
            return recurse(node->left, left, node->val) &&
                   recurse(node->right, node->val, right);
        } else {
            return false;
        }
    }
};
