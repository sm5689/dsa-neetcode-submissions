class Solution {
public:
    vector<int> topoSort(vector<bool>& present, unordered_map<int, vector<int>>& adj) {
        queue<int> q;
        vector<int> indegree(26, 0);
        vector<int> topo;
        for (auto it : adj) {
            int node = it.first;
            for (int i = 0; i< it.second.size(); i++) {
                int adjNode = it.second[i];
                indegree[adjNode]++;
            }
        }

        for (int i = 0; i< indegree.size(); i++) {
            if (indegree[i] == 0 && present[i] == true) q.push(i);
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            topo.push_back(front);
            for (auto adjNode : adj[front]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }

        return topo;

    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<int, vector<int>> adj;
        vector<bool> present(26, false);
        for (string word : words) {
            for (char ch : word) {
                present[ch-'a'] = true;
            }
        }
        for (int i = 0; i< words.size()-1; i++) {
            string one = words[i];
            string two = words[i+1];
            if (one.length() > two.length() && one.substr(0, two.length()) == two) return "";
            for (int j = 0; j< min(one.length(), two.length()); j++) {
                if (one[j] != two[j]) {
                    adj[one[j]-'a'].push_back(two[j]-'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(present, adj);
        int distinctChars = count(present.begin(), present.end(), true);
        if (topo.size() != distinctChars) return "";
        string ans = "";
        for (int i = 0; i< topo.size(); i++) {
            char ch = char(topo[i]+'a');
            ans+= ch;
        }

        return ans;
    }
};
