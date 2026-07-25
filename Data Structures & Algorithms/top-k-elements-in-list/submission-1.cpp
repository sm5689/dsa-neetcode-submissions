class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int maxi = -1;
        for (auto num : nums) {
            freq[num]++;
        }
        vector<vector<int>> buckets(n+1);
        for (auto it : freq) {
            buckets[it.second].push_back(it.first);
        }
        vector<int> ans;
        int i = buckets.size()-1;
        int cnt = 0;
        while (i >= 0 && cnt < k) {
            if (!buckets[i].empty()) {
                for (int j = 0; j< buckets[i].size() && j < k; j++) {
                    ans.push_back(buckets[i][j]);
                    cnt++;
                }
            }
            i--;
        }
        return ans;
    }
};
