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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        if (!p || !q) return root;

        //  Root, P and Q are valid
        if (p->val < root->val && q->val > root->val || p->val > root->val && q->val < root->val)
        {
            return root;
        }
        else if (root == p || root == q)
        {
            return root;
        }
        else
        {
            TreeNode* l = lowestCommonAncestor(root->left,  p, q);
            TreeNode* r = lowestCommonAncestor(root->right, p, q);
            if (l) return l;
            if (r) return r;
            return nullptr;
        }
    }
};
