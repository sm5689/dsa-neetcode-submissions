class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> visited(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // start with 0th index in points with node 0 and dist = 0; {dist, node}
        pq.push({0, 0});
        int totalCost = 0;
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int dist = top.first;
            int node = top.second;
            if (visited[node]) continue;
            visited[node] = 1;
            totalCost+=dist;
            for (int i = 0; i< n; i++) {
                if (i == node) continue;
                int newDist = abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                if (visited[i] != 1) {
                    pq.push({newDist, i});
                }
            }
        }
        return totalCost;
    }
};
