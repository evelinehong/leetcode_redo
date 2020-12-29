class Solution {
public:
    int minDistance(string word1, string word2) {
        word2 = " " + word2;
        word1 = " " + word1;
        
        int m = word2.size(), n = word1.size();
        
        vector<vector<int>> dp (m, vector<int>(n, 0));
        
        dp[0][0] = 0;
        for (int i = 1; i < m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){      
                if (!(word2[i] == word1[j])) dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                else dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};