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
        if (!root) { return true; }

        return check(root->left, INT_MIN, root->val) && check(root->right, root->val, INT_MAX);
    }

    bool check(TreeNode* node, int leftbd, int rightbd)
    {
        if (!node) { return true; }

        if (node->val > leftbd && node->val < rightbd)
        {
            // Recurse
            return check(node->left, leftbd, node->val) && check(node->right, node->val, rightbd);
        }
        else
        {
            return false;
        }
    }
};
