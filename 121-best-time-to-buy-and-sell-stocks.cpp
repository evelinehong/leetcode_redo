class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = -1, mini = INT_MAX;
        int res = 0;
        for (int i = 0; i < n; i++){
            if (prices[i] > maxi) {
                maxi = prices[i];
                res = max(res, maxi-mini);
            }
            if (prices[i] < mini) {
                maxi = -1;
                mini = prices[i];
            }
        }
        return res;
    }
};