class Solution {
public:
    int dp[120];
    int numDecodings(string s) {
        fill(dp, dp + 120,-1);
        return s.empty()? 0: numDecodings(0, s);
    }
    int numDecodings(int idx, string &s){
        if (~dp[idx]) return dp[idx];
        if (s[idx] == '0') return 0; 
        if (idx == s.length() || idx == s.length()-1) return 1;
        if (idx < s.length()-1 && (s[idx] == '1' || s[idx] == '2' && s[idx+1] < '7')){
            return dp[idx] = numDecodings(idx+2, s) + numDecodings(idx+1, s);
        } 
            
        else {
            return dp[idx] = numDecodings(idx+1, s);
        }
    }
};

class Solution {
public:
    
    int numDecodings(string s) {
        s = "99" + s;
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < s.size(); i++) {
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) dp[i] += dp[i-2];
            if (s[i] != '0') dp[i] += dp[i-1];
        }
        return dp[s.size() - 1];
    }
};