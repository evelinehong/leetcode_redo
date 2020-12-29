class Solution {
public:
    int res = 0;
    int coinChange(vector<int>& coins, int amount) {
        int max = 10000;
        vector<int> dp (amount + 1, max);
        dp[0] = 0;
        for (auto &coin: coins){
            for (int v = coin; v <= amount; v++) {
                dp[v] = min(dp[v], dp[v-coin] + 1);
            }
        }
        if (dp[amount] == 10000) return -1;
        else return dp[amount];
    }
};