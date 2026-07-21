class Solution {
public:

    // TOPOLOGICAL SORT BASED PROBLEM


    // create the Adjacency List first.
    vector<vector<int>> adjList(vector<vector<int>>& prerequisites, int numCourses) {
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i< prerequisites.size(); i++) {
            int b = prerequisites[i][0];
            int a = prerequisites[i][1];
            adj[a].push_back(b);
        }

        return adj;
    }

    // Create the list containing indegreeCount for all the nodes.
    vector<int> indegreeCount(vector<vector<int>> &adjList, int numCourses) {
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i< numCourses; i++) {
            for (int j = 0; j< adjList[i].size(); j++) {
                indegree[adjList[i][j]]++;
            }
        }
        return indegree;
    }

    // Then finally, use the main loop logic for topological sort;
    // create the queue, and start to input the elements which have 0 indegree counts.
    // After pushing them elements, pop them as well and reduce their neighbor's indegree counts accordingly.
    // As the indegree Count for the neighbors reduce, we simultaneously check if the elements' indegree count becomes 0 or not.
    // If the new indegree count is 0, we push it in the queue and continue the process.
    // Along with all this, in the main loop, we maintain a COUNTER.
    // At the end, we check if this counter value is equal to the total number of nodes/
    // If the value of the counter is equal to the nodes, we return true, else false.
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = adjList(prerequisites, numCourses);
        vector<int> indegree = indegreeCount(adj, numCourses);
        queue<int> q;

        for (int i = 0; i< indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int processedCount = 0;
        
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            processedCount++;

            for (int i = 0; i< adj[front].size(); i++) {
                indegree[adj[front][i]]--;
                if (indegree[adj[front][i]] == 0) {
                    q.push(adj[front][i]);
                }
            }
        }
        return processedCount==numCourses;
    }
};
