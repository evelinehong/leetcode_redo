class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> left (n,-1), right (n,n), height (n,0);
        int area = 0;
        for (int i = 0; i < m; i++){
            int leftmin = 0;
            int rightmax = n - 1;
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == '1'){
                    left[j] = max(left[j], leftmin);
                    height[j] += 1;
                }
                else {
                    left[j] = -1;
                    leftmin = j + 1;
                    height[j] = 0;
                }
                if (matrix[i][n-1-j] == '1'){
                    right[n-1-j] = min(right[n-1-j], rightmax);
                }
                else {
                    right[n-1-j] = n;
                    rightmax = n - j - 2;
                } 
            }      
            for (int j = 0; j < n; j++){
                area = max(area, (right[j] - left[j] + 1) * height[j]);
            }
        }
        return area;
    }
};