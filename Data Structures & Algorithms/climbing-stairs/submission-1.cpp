class Solution {
public:
    int climbStairsDP(int n, vector<int>& dp) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = climbStairsDP(n-1, dp) + climbStairsDP(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return climbStairsDP(n, dp);
    }
};
