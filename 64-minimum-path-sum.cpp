class Solution {
public:
    
    
//     vector<int> dx {0, -1}, dy {-1, 0};
//     int minPathSum(vector<vector<int>>& grid) {
//         if (grid.empty()) return 0;
//         std::vector<std::vector<int>>dp (grid.size(), std::vector<int>(grid[0].size(), 0x3f3f3f3f));
//         return minPathSum(grid, grid.size() - 1, grid[0].size() - 1, dp);
//     }
//     int minPathSum(vector<vector<int>>& grid, int row, int col, vector<vector<int>> &dp){
//         if (dp[row][col] != 0x3f3f3f3f) return dp[row][col];
//         if (row == 0 && col == 0) return grid[row][col];
        
//         for (int i = 0; i < 2; i++){
//             int nrow = row + dx[i];
//             int ncol = col + dy[i];
//             if (nrow >= 0 && ncol >= 0){
//                 dp[row][col] = min(dp[row][col], grid[row][col] + minPathSum(grid, nrow, ncol, dp));
//             }
//         }
//         return dp[row][col];
//     }
    int minPathSum(vector<vector<int>>& grid){
        if (grid.empty()) return 0;
        vector<vector<int>> dp (grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (int j = 1; j < grid[0].size(); j++) dp[0][j] = dp[0][j-1] + grid[0][j];
        for (int i = 1; i < grid.size(); i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        
        for (int i = 1; i < grid.size(); i++){
            for (int j = 1; j < grid[0].size(); j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};


class Solution {
public:
    int dp[210][210];
    
    vector<int> dx {0, -1}, dy {-1, 0};
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        std::memset(dp,0x3f,sizeof dp);
        return minPathSum(grid, grid.size() - 1, grid[0].size() - 1);
    }
    int minPathSum(vector<vector<int>>& grid, int row, int col){
        if (dp[row][col] != 0x3f3f3f3f) return dp[row][col];
        if (row == 0 && col == 0) return grid[row][col];
        
        for (int i = 0; i < 2; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && ncol >= 0){
                dp[row][col] = min(dp[row][col], grid[row][col] + minPathSum(grid, nrow, ncol));
            }
        }
        return dp[row][col];
    }
    // int minPathSum(vector<vector<int>>& grid){
    //     vector<vector<int>> dp (grid.size(), (grid[0].size(), ));
    //     dp[0][0] = grid[0][0];
    //     for (int j = 0)
    // }
};