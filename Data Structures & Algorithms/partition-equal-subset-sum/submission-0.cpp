class Solution {
public:
    bool partition(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (index >= nums.size() || target < 0) return false;
        if (dp[index][target] != -1) return dp[index][target];
        return dp[index][target] = partition(index+1, target-nums[index], nums, dp) || partition(index+1, target, nums, dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum+= num;
        }
        if (sum % 2 != 0) return false;
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, -1));
        return partition(0, sum/2, nums, dp);
    }
};
