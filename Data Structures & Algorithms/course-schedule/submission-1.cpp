class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;

        for (int i = 0; i< prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[u].push_back(v);
        }

        vector<int> inorder(numCourses, 0);

        for (int i = 0; i< numCourses; i++) {
            for (int j = 0; j< adjList[i].size(); j++) {
                inorder[adjList[i][j]]++;
            }
        }

        queue<int> q;

        for (int i = 0; i< numCourses; i++) {
            if (inorder[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (auto adj : adjList[node]) {
                inorder[adj]--;
                if (inorder[adj] == 0) q.push(adj);
            }
        }

        return count == numCourses;
    }
};
