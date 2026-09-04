class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> timings(n+1, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i< times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            adj[u].push_back({v, t});
        }
        timings[0] = 0;
        timings[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int time = front.first;
            int node = front.second;
            for (int i = 0; i< adj[node].size(); i++) {
                int adjNode = adj[node][i].first;
                int adjTime = adj[node][i].second;
                if (time+adjTime < timings[adjNode]) {
                    timings[adjNode] = time+adjTime;
                    pq.push({time+adjTime, adjNode});
                }
            }
        }
        int totalTime = 0;
        for (auto num : timings) {
            if (num == INT_MAX) return -1;
            totalTime = max(totalTime, num);
        }
        return totalTime;
    }
};
