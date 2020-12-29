class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int vertical = matrix.size()-1;
        if (vertical == -1) return {};
        int horizon = matrix[0].size();
        if (horizon == 0) return {};
        vector<int> steps{horizon, vertical};
        vector<vector<int>> moves = {{0,1}, {1,0}, {0,-1}, {-1,0}};      
        int i = 0, j = -1, m = 0, s = 0;
        vector<int> res;
        while (steps[s]){
            for (int k = 0; k < steps[s]; k++){                
                i += moves[m][0];
                j += moves[m][1];
                res.push_back(matrix[i][j]);
            }
            steps[s]--;
            m = (m + 1) % 4;            
            s = (s + 1) % 2;
        }
        return res;
    }
};