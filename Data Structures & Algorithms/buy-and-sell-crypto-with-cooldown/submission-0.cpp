class Solution {
public:
    int maxProfitHelper(int index, bool canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        if (index >= prices.size()) return 0;
        if (dp[index][canBuy] != -1) return dp[index][canBuy];
        int profit = INT_MIN;
        if (canBuy == 1) {
            profit = max(profit, max(-prices[index]+maxProfitHelper(index+1, !canBuy, prices, dp), 0+maxProfitHelper(index+1, canBuy, prices, dp)));
        }
        else {
            profit = max(profit, max(0+maxProfitHelper(index+1, canBuy, prices, dp), prices[index]+maxProfitHelper(index+2, !canBuy, prices, dp)));
        }
        return dp[index][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
        return maxProfitHelper(0, true, prices, dp);
    }
};
