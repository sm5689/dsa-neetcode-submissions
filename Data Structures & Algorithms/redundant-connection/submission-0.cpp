class DisjointSet{
    vector<int> size;
    vector<int> parent;
    public:
        DisjointSet(int n) {
            size.resize(n+1, 1);
            parent.resize(n+1);
            for (int i = 0; i< n+1; i++) {
                parent[i] = i;
            }
        }

        int findUPar(int u) {
            if (parent[u] == u) return u;
            return parent[u] = findUPar(parent[u]);
        }

        bool find(int u, int v) {
            return findUPar(u) == findUPar(v);
        }

        void unionBySize(int u, int v) {
            int u_par_u = findUPar(u);
            int u_par_v = findUPar(v);
            if (u_par_u == u_par_v) return;
            if (size[u_par_u] > size[u_par_v]) {
                size[u_par_u] += size[u_par_v];
                parent[u_par_v] = parent[u_par_u];
            }
            else {
                size[u_par_v] += size[u_par_u];
                parent[u_par_u] = parent[u_par_v];
            }
        }

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds1(n);
        vector<int> extras;
        for (int i = 0; i< n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (!ds1.find(u, v)) {
                ds1.unionBySize(u, v);
            }
            else {
                extras.push_back(u);
                extras.push_back(v);
            }
        }
        return extras;
    }
};
