class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        vector<int> first, second;

        // Step 1: Check if any node has two parents
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (parent[v] != v) {
                first = {parent[v], v};
                second = {u, v};

                e[1] = 0;  // Temporarily remove second edge
            } else {
                parent[v] = u;
            }
        }

        // Step 2: Reset DSU
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        // Step 3: Detect cycle using DSU
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (v == 0)
                continue;

            int pu = find(u);
            int pv = find(v);

            if (pu == pv) {
                if (first.empty())
                    return e;

                return first;
            }

            parent[pu] = pv;
        }

        // Step 4: No cycle, so remove second edge
        return second;
    }
};