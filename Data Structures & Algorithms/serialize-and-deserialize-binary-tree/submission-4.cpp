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

class Codec {
public:

    void dfs(TreeNode* node, string& r) {
        if (!node) {
            r.append("N");
            r.append(",");
            return;
        }
        r.append(to_string(node->val));
        r.append(",");
        dfs(node->left,  r);
        dfs(node->right, r);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Re-implementing with BFS
        string r;
        dfs(root, r);
        return r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> elems;
        string tmp;
        for (int i = 0; i < data.length(); ++i) {
            while (i < data.length() && data[i] != ',') {
                tmp += data[i];
                i++;
            }
            elems.push_back(tmp);
            tmp = "";
        }

        TreeNode* root = nullptr;
        int i = 0;
        dfs_deserialize(root, elems, i);
        return root;
    }

    void dfs_deserialize(TreeNode*& node, vector<string>& elems, int& i) {
        if (i >= elems.size() || elems[i] == "N" || i >= elems.size()) {
            node = nullptr;
            i++;
            return;
        }

        node = new TreeNode(stoi(elems[i]));
        i = i + 1;
        dfs_deserialize(node->left,  elems, i);
        dfs_deserialize(node->right, elems, i);
    }
};
