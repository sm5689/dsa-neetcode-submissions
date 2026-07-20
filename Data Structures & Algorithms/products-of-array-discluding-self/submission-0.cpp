class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix[n];
        int suffix[n];
        prefix[0] = 1, suffix[n-1] = 1;
        for (int i = 1; i< n; i++) {
            prefix[i] = prefix[i-1]*nums[i-1];
            suffix[n-1-i] = suffix[n-i]*nums[n-i];
        }
        vector<int> productsExceptSelf(n);
        for (int i = 0; i< n; i++) {
            productsExceptSelf[i] = prefix[i]*suffix[i];
        }
        return productsExceptSelf;
    }
};
