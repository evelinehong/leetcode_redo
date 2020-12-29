class Solution {
public:
    vector<int> dx {1,0,-1,0}, dy {0,1,0,-1};
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    numIslands(i, j, grid);
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
    
    void numIslands(int x, int y, vector<vector<char>>& grid){
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++){
            int ndx = x + dx[i];
            int ndy = y + dy[i];
            if (ndx >= 0 && ndy >= 0 && ndx < grid.size() && ndy < grid[0].size() && grid[ndx][ndy] == '1') {
                numIslands(ndx, ndy, grid);
            }
        }
    }
};



class Solution {
public:
    void solve(vector<vector<char>>& grid, int x, int y){
        int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
        queue<pair<int, int>> q;
        q.push({x,y});
        grid[x][y] = '0';
        while(q.size()){
            int sz = q.size();
            auto cur = q.front(); q.pop();
            while(sz--){
                for(int i = 0; i < 4; i++){
                    int nx = cur.first + dx[i], ny = cur.second + dy[i];
                    if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
                    if (grid[nx][ny] == '1'){
                        q.push({nx,ny});
                        grid[nx][ny] = '0';
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        const int M = grid.size(), N = grid[0].size();
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if (grid[i][j] == '1'){
                    solve(grid,i,j);
                    island += 1;
                }   
            }
        }
        return island;
    }
};