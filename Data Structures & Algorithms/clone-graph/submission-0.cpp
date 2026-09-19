/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldNewMap;
        Node* clone = nullptr;
        queue<Node*> q; 
        if (node) {
            oldNewMap[node] = new Node(node->val);
            q.push(node);
        }

        while (!q.empty()) {
            Node* oldNode = q.front();
            q.pop();

            // If no mapping exists for all these neighbors; push them on the queue
            for (auto nbr : oldNode->neighbors) {
                // Couldn't find this neighbor
                if (oldNewMap.find(nbr) == oldNewMap.end()) {
                    oldNewMap[nbr] = new Node(nbr->val);
                    q.push(nbr);
                } 
                oldNewMap[oldNode]->neighbors.push_back(oldNewMap[nbr]);
            }
        }

        return oldNewMap[node];
    }
};
