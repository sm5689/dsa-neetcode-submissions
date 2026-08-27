class Solution {
public:
    int helper(int index, vector<int>& nums, int target, map<pair<int, int>, int>& dp) {
        if (index == nums.size()) {
            if (target == 0) return 1;
            else return 0;
        }
        if (dp.find({index, target}) != dp.end()) return dp[{index, target}];
        int add = helper(index+1, nums, target+nums[index], dp);
        int subtract = helper(index+1, nums, target-nums[index], dp);
        return dp[{index, target}] = add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return helper(0, nums, target, dp);
    }
};
