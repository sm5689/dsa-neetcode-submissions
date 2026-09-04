class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> inorder(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i< prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            inorder[u]++;
            adj[v].push_back(u);
        }
        int cnt = 0;
        for (int i = 0; i< numCourses; i++) {
            if (inorder[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            cnt++;
            for (int i = 0; i< adj[front].size(); i++) {
                inorder[adj[front][i]]--;
                if (inorder[adj[front][i]] == 0) q.push(adj[front][i]);
            }
        }
        return cnt == numCourses;
    }
};
