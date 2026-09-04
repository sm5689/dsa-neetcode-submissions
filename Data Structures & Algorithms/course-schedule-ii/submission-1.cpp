class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i< prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            indegree[u]++;
            adj[v].push_back(u);
        }
        int cnt = 0;
        for (int i = 0; i< numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            cnt++;
            ans.push_back(front);
            for (int i = 0; i< adj[front].size(); i++) {
                indegree[adj[front][i]]--;
                if (indegree[adj[front][i]] == 0) q.push(adj[front][i]);
            }
        }
        return cnt == numCourses ? ans : vector<int>();
    }
};
