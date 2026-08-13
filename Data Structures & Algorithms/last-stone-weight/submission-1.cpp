class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mx_pq;
        for (int i = 0; i< stones.size(); i++) {
            mx_pq.push(stones[i]);
        }
        while (mx_pq.size() != 1 || mx_pq.size() > 1) {
            int curr_max = mx_pq.top();
            mx_pq.pop();
            int new_maxi = curr_max-(mx_pq.size()==0?0:mx_pq.top());
            mx_pq.pop();
            mx_pq.push(new_maxi);
        }
        return mx_pq.top();
    }
};
