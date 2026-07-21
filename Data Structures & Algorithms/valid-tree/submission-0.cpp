class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<bool> visited(n, false);

        queue<pair<int, int>> q;

        q.push({0, -1});
        visited[0] = true;

        unordered_map<int, vector<int>> adjList;

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjNode : adjList[node]) {
                
                if (adjNode == parent) continue;
                
                if (visited[adjNode]) {
                    return false;
                }
                
                q.push({adjNode, node});
                visited[adjNode] = true;
            }
        }

        for (int i = 0; i< n; i++) {
            if (visited[i] != true) {
                return false;
            }
        }

        return true;
    }
};
