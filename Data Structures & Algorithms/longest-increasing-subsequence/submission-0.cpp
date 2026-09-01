class Solution {
public:
    int lisHelper(int index, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (index == nums.size()) return 0;
        if (dp[index][prev+1] != -1) return dp[index][prev+1];
        int notTake = 0 + lisHelper(index+1, prev, nums, dp);
        int take = 0;
        if (prev == -1 || nums[index] > nums[prev]) {
            take += 1+lisHelper(index+1, index, nums, dp);
        }
        return dp[index][prev+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return lisHelper(0, -1, nums, dp);
    }
};
