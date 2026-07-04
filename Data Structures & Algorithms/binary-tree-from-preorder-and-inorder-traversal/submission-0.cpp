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

class Solution 
{
public:
    unordered_map<int, int> inorderIndices;
    vector<int> preorder;
    vector<int> inorder;


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder  = inorder;
        for (int i = 0; i < inorder.size(); ++i) { inorderIndices[inorder[i]] = i; }

        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* build(int preStart, int preEnd, int inStart, int inEnd) 
    {
        if (preStart > preEnd || inStart > inEnd) { return nullptr; }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndices[rootVal];
        int size = mid - inStart;

        root->left = build(preStart + 1, preStart + size, inStart, mid - 1);
        root->right = build(preStart + size + 1, preEnd, mid + 1, inEnd);

        return root;
    }
};
