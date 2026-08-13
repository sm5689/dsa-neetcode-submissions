class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int len;
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) {
            if (pq.empty() || pq.size() < k) pq.push(num);
            else {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
        this->len = k;
    }
    
    int add(int val) {
        if (pq.empty() || pq.size() < this->len) pq.push(val);
        else {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};
