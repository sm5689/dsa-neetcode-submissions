class Solution {
public:
    int helper(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount < 0) return 0;
        if (amount == 0) return 1;
        if (index == coins.size()) {
            if (amount == 0) return 1;
            else return 0;
        }
        if (dp[index][amount] != -1) return dp[index][amount];
        int notTake = helper(index+1, amount, coins, dp);
        int take = helper(index, amount-coins[index], coins, dp);
        return dp[index][amount] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return helper(0, amount, coins, dp);
    }
};
