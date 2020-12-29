struct node {
    int x;
    int y;
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<node> rotten;
        int m = grid.size(), n = grid[0].size();
        vector<int> dx{-1,0,1,0}, dy{0,-1,0,1};
        int minute = 0;
        int oranges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    rotten.push({i,j});
                }          
                if (grid[i][j] != 0) oranges += 1;
            }
        }
        int rotted = 0;
        while (!rotten.empty()){
            int siz = rotten.size();
            rotted += siz;
            for (int i = 0; i < siz; i++){
                node orange = rotten.front();
                rotten.pop();
                for (int d = 0; d < 4; d++){
                    int x = orange.x + dx[d];
                    int y = orange.y + dy[d];
                    if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1){
                        rotten.push({x,y});
                        grid[x][y] = 2;
                    }
                }
            }
            if (!rotten.empty()) minute++;
        }
        if (!(oranges == rotted)) return -1; 
        return minute;
    }
};