class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> costings(n, INT_MAX);
        costings[src] = 0;
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i< flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            adj[u].push_back({v, cost});
        }
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int stops = front.first;
            int node = front.second.first;
            int cost = front.second.second;
            if (stops > k) continue;
            for (int i = 0; i< adj[node].size(); i++) {
                int adjNode = adj[node][i].first;
                int adjCost = cost+adj[node][i].second;
                if (adjCost < costings[adjNode]) {
                    costings[adjNode] = adjCost;
                    q.push({stops+1, {adjNode, adjCost}});
                }
            }
        }
        return costings[dst]==INT_MAX?-1:costings[dst];
    }
};
