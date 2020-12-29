class Solution {
public:
    vector<int> dx{0,1,0,-1}, dy{1,0,-1,0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1) area  = max(area, maxAreaOfIsland(grid, i, j));
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid, int row, int col){
        grid[row][col] = 0;
        int sum = 1;
        for (int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow < grid.size() && nrow >= 0 && ncol < grid[0].size() && ncol >= 0 && grid[nrow][ncol]) {
                sum += maxAreaOfIsland(grid, nrow, ncol);
            }
        }
        return sum;
    }
};