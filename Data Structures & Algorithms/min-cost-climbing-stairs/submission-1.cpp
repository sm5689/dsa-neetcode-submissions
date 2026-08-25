class Solution {
public:
    int helper(int index, vector<int>& cost, vector<int>& dp) {
        if (index >= cost.size()) return 0;
        if (dp[index] != -1) return dp[index];
        int oneStep = cost[index]+helper(index+1, cost, dp);
        int twoStep = cost[index]+helper(index+2, cost, dp);
        return dp[index] = min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return min(helper(0, cost, dp), helper(1, cost, dp));
    }
};
