class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        queue<pair<int, char>> q;
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mpp;
        for (auto ch : tasks) mpp[ch]++;
        for (auto it : mpp) pq.push({it.second, it.first});
        int time = 0;
        while (!pq.empty()) {
            for (int i = 0; i< n+1; i++) {
                if (!pq.empty()) {
                    auto top = pq.top();
                    pq.pop();
                    if (top.first-1 > 0) q.push({top.first-1, top.second});
                }
                time++;
                if (pq.empty() && q.empty()) break;
            }
            while (!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
        }
        return time;
    }
};
