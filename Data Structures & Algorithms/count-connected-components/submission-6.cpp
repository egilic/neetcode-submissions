class Solution {
public:
    vector<int> parents;
    vector<int> ranks;
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents_(n, 0);
        vector<int> ranks_(n, 1);
        for (int i = 0; i < n; i += 1) {
            parents_[i] = i;
        }
        parents = parents_;
        ranks = ranks_;

        int res = n;
        for (int i = 0; i < edges.size(); i += 1) {
            res -= union_nodes(edges[i][0], edges[i][1]);
        }
        return res;
    }

    int find(int node) {
        int res = node;
        while (res != parents[res]) {
            parents[res] = parents[parents[res]];
            res = parents[res];
        }
        return res;
    }

    int union_nodes(int node1, int node2)  {
        int p1 = node1, p2 = node2;
        p1 = find(node1);
        p2 = find(node2);

        if (p1 == p2) return 0;

        if (ranks[p2] > ranks[p1]) {
            parents[p1] = p2;
            ranks[p2] += ranks[p1];
        } else {
            parents[p2] = p1;
            ranks[p1] = ranks[p2];
        }
        return 1;
    }
};
