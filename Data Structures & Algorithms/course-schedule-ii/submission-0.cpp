class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adjList;

        for (int i = 0; i< prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
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

        vector<int> orderedList;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            orderedList.push_back(node);
            for (auto adj : adjList[node]) {
                inorder[adj]--;
                if (inorder[adj] == 0) q.push(adj);
            }
        }

        return orderedList.size() == numCourses ? orderedList : vector<int>(0);
    }
};
