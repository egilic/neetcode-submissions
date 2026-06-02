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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if (!root) return 0;
        int _max = 0;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int sum = 0;
            sum += maxDepth(top->left);
            sum += maxDepth(top->right);
            _max = max(_max, sum);
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
        }



        return _max;
    }

    int maxDepth(TreeNode* t)
    {
        if (!t) return 0;

        int sum = 1;
        sum += max(maxDepth(t->left), maxDepth(t->right));
        return sum;
    }
};
