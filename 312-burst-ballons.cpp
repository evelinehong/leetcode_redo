class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        vector<int> nums2 (N+2, 1);
        
        for (int i = 0; i < N; i++){
            nums2[i+1] = nums[i];
        }
        N = nums2.size();
        vector<vector<int>> dp (N, vector<int>(N, 0));
        for (int len = 3; len <= N; len++){
            for (int i = 0; i <= N - len; i++){
                int j = i + len - 1;
                for (int k = i + 1; k < j; k++){
                    dp[i][j] = max(dp[i][j], nums2[i]*nums2[j]*nums2[k] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][N-1];
    }

};