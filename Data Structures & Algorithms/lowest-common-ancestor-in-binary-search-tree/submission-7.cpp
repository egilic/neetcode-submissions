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
    TreeNode* lca = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca = root;
        search(root, p, q);
        return lca;
    }

    void search(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root) return;

        lca = root;
        if (root == p || root == q)
        {
            return;
        }
        else if (root->val > p->val && root->val > q->val)
        {
            search(root->left, p, q);
        }
        else if (root->val < p->val && root->val < q->val)
        {
            search(root->right, p, q);
        }
        else
        {
            return;
        }
    }
};
