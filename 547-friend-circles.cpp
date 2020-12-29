class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int sum = 0;
        for (int i = 0; i < M.size(); i++){
            if (!M[i][i]) continue;
            else {
                findCircleNum(M, i);
                sum += 1;
            }
        }
        return sum;
        
    }
    void findCircleNum(vector<vector<int>>& M, int p) {
        M[p][p] = 0;
        for (int i = 0; i < M.size(); i++){
            if (i != p && M[p][i] == 1) {
                M[p][i] = 0;
                M[i][p] = 0;
                findCircleNum(M, i);
            }
        }
    }
};