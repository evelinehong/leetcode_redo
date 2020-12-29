class Solution {
public:
    bool isMatch(string s, string p) {
//         if (p.empty()) return s.empty();
//         int n = 0;
//         if (p[0] == '*') {
//             while (n < p.size() && p[n] == '*'){
//                 n++;
//             }
//             return (!s.empty() && (isMatch(s.substr(1), p) || isMatch(s, p.substr(n)))) || (s.empty() && isMatch(s, p.substr(n)));
//         }
        
//         int m = 0;
//         if (m < s.size() && (s[0] == p[0] || p[0] == '?')){
//             while (m < s.size() && (s[m] == p[m] || p[m] == '?')) 
//             m++;
//             return isMatch (s.substr(m), p.substr(m));
//         }
        
//         return false;
        s = " " + s;
        p = " " + p;
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp (n, vector<bool> (m,false));
        dp[0][0] = true;
        for (int j = 1; j < m; j++) dp[0][j] = false;
        for (int i = 1; i < n; i++) dp[i][0] = (p[i] == '*' && dp[i-1][0])? true: false;
        
        for (int i = 1; i < n; i++){
            bool terminate = false;
            for (int j = 1; j < m; j++){
                
                if (p[i] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = (p[i] == s[j] || p[i] == '?') && dp[i-1][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};