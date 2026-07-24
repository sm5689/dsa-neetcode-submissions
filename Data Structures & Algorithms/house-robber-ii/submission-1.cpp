class Solution {
public:
    int robDPHelper(int index, int end, vector<int>& nums, vector<int>& dp) {
        if (index > end) return 0;
        if (index == end) return nums[index];
        if (dp[index] != -1) return dp[index];
        int take = nums[index]+robDPHelper(index+2, end, nums, dp);
        int notTake = robDPHelper(index+1, end, nums, dp);
        return dp[index] = max(take, notTake);
    }
     int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size()+1, -1);
        vector<int> dp2(nums.size()+1, -1);
        return max(robDPHelper(0, nums.size()-2, nums, dp), robDPHelper(1, nums.size()-1, nums, dp2));
    }
};
