class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum, N = nums.size();
        vector<int> dp (N, 0);
        dp[0] = nums[0];
        sum = dp[0];
        for (int i = 1; i < N; i++) {
            if (dp[i - 1] < 0) dp[i] = nums[i];
            else dp[i] = dp[i - 1] + nums[i];
            sum = max(sum, dp[i]);
        }
        return sum;
    }

};