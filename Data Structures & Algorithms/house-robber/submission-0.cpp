class Solution {
public:
    int robDPHelper(int index, vector<int>& nums, vector<int>& dp) {
        if (index == nums.size()-1) return nums[index];
        if (index >= nums.size()) return 0;
        if (dp[index] != -1) return dp[index];
        return dp[index] = max(robDPHelper(index+1, nums, dp), (nums[index]+robDPHelper(index+2, nums, dp)));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return robDPHelper(0, nums, dp);
    }
};
