class Solution {
public:
    bool dfs(int node, int visitedMask, int n, vector<vector<int>>& adj) {
 
        if (visitedMask == (1 << n) - 1)
            return true;

        for (int next : adj[node]) {
            if (!(visitedMask & (1 << next))) {
                if (dfs(next, visitedMask | (1 << next), n, adj))
                    return true;
            }
        }
        return false;
    }

    bool check(int n, int m, vector<vector<int>> edges) {

        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

   
        for (int start = 0; start < n; start++) {
            if (dfs(start, 1 << start, n, adj))
                return true;
        }

        return false;
    }
};
