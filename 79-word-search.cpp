const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
class Solution {
public:
    int N,M,len;
    
    bool visited[300][300];
    bool exist(vector<vector<char>>& board, string word) {
        N = board.size(), M = board[0].size(),len = word.size();
        std::memset(visited,0,sizeof visited);
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] != word[0]) continue;
                visited[i][j] = 1;
                if (exist(board, word, 1, i, j)) return true;     
                visited[i][j] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string &word, int idx, int row, int col ){
        if (idx == len) return true;
        for(int i = 0; i < 4; i++){
            int nx = row + dx[i], ny = col + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] || board[nx][ny] != word[idx]) continue;
            visited[nx][ny] = 1;
            if ( exist(board,word,idx + 1, nx, ny)) return true;
            visited[nx][ny] = 0;
        }
        return false;
    }
};