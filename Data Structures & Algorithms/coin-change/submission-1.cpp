class Solution {
public:
    int coinChangeHelper(int index, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (index == coins.size() - 1) {
            if (amount % coins[index] == 0) return amount/coins[index];
            else return 1e9;
        }
        if (dp[index][amount] != -1) return dp[index][amount];
        int notTake = coinChangeHelper(index+1, coins, amount, dp);
        int take = INT_MAX;
        if (coins[index] <= amount) take = 1+coinChangeHelper(index, coins, amount-coins[index], dp);
        return dp[index][amount] = min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) return 0;
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return coinChangeHelper(0, coins, amount, dp) == 1e9 ? -1 : coinChangeHelper(0, coins, amount, dp);
    }
};
