class Solution {
public:
    int coinChangeHelper(int index, vector<int>& coins, int amount) {
        if (index == coins.size() - 1) {
            if (amount % coins[index] == 0) return amount/coins[index];
            else return 1e9;
        }
        int notTake = coinChangeHelper(index+1, coins, amount);
        int take = INT_MAX;
        if (coins[index] <= amount) take = 1+coinChangeHelper(index, coins, amount-coins[index]);
        return min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) return 0;
        return coinChangeHelper(0, coins, amount) == 1e9 ? -1 : coinChangeHelper(0, coins, amount);
    }
};
