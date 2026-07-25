class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        for (auto num : nums) {
            freq[num]++;
        }
        for (auto it : freq) {
            pq.push({it.second, it.first});
        }
        int i = 0;
        vector<int> ans;
        while (!pq.empty() && i != k) {
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return ans;
    }
};
