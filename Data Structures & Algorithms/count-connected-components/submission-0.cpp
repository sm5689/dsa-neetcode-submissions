class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adjList;

        vector<bool> visited(n, false);

        for (int i = 0; i< edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        queue<int> q;

        int count = 0;

        for (int i = 0; i< n; i++) {
            if (!visited[i]) {
                count++;
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto adjNode : adjList[node]) {
                        if (!visited[adjNode]) {
                            q.push(adjNode);
                            visited[adjNode] = true;
                        }
                    }
                }
            }
        }
        return count;
    }
};
