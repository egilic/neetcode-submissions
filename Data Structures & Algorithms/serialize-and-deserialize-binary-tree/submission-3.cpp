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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) { return ""; }

        string serialized_tree;

        // Perform level order traversal
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t size = q.size();
            for (size_t i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();

                if (node) {
                    serialized_tree.append(to_string(node->val));
                    serialized_tree.append(",");
                    q.push(node->left); q.push(node->right);
                } else {
                    serialized_tree.append("x,");
                }
            }
        }

        return serialized_tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << "deserialize data is " << data << "\n";
        // cout << "size is " << data.length() << "\n";
        if (data.length() == 0) { return nullptr; }

        TreeNode* head = new TreeNode();
        size_t i = 0, n = data.length();
        size_t level_width = 2;

        queue<TreeNode*> previous_level_nodes;
        string value_string = "";
        while (i < n && data[i] != ',') {
            value_string += data[i++];
        }
        i++; // ** skip comma
        // cout << "attempting to convert to int: " << value_string << "\n";
        head->val = stoi(value_string);
        previous_level_nodes.push(head);

        while (i < n) {
            size_t sz = previous_level_nodes.size();
            for (size_t j = 0; j < sz; j = j + 2) {
                TreeNode* parent = previous_level_nodes.front();
                previous_level_nodes.pop();

                // Handle left side
                // Read from data string until we find a ","
                string l_value_string = "";
                while (i < n && data[i] != ',') {
                    l_value_string += data[i++];
                }
                i++; // ** skip comma

                if (l_value_string != "x" && l_value_string != "" && l_value_string != ",") {
                    // cout << "l attempting to convert to int: " << l_value_string << "\n";
                    int value = stoi(l_value_string);
                    parent->left = new TreeNode(value);
                    previous_level_nodes.push(parent->left);
                }


                // Handle right side
                // Read from data string until we find a ","
                string r_value_string = "";
                while (i < n && data[i] != ',') {
                    r_value_string += data[i++];
                }
                i++; // ** skip comma

                if (r_value_string != "x" && r_value_string != "" && r_value_string != ",") {
                    // cout << "r attempting to convert to int: " << r_value_string << "\n";
                    int value = stoi(r_value_string);
                    parent->right = new TreeNode(value);
                    previous_level_nodes.push(parent->right);
                }
            }
        }
        return head;
    }
};
