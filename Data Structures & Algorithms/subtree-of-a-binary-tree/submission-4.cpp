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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot || !root) return true;
        if (!root && subRoot) return false;

        stack<TreeNode*> s;
        queue<TreeNode*> potCurRootNodes;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();
            if (cur->val == subRoot->val)
            {
                potCurRootNodes.push(cur);
            }
            if (cur->left)  s.push(cur->left);
            if (cur->right) s.push(cur->right);
        }


        while (!potCurRootNodes.empty())
        {
            TreeNode* t = potCurRootNodes.front();
            potCurRootNodes.pop();
            if (isSameTree(t, subRoot))
            {
                return true;
            }
        }
        return false;
    }

    bool isSameTree(TreeNode* r, TreeNode* s)
    {
        if (!r && !s) return true;
        if (!r || !s) return false;

        if (!isSameTree(r->left, s->left) || !isSameTree(r->right, s->right))
        {
            return false;
        }

        return (r->val == s->val);
    }
};
