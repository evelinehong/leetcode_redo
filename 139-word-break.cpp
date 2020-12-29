class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector <bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++){
            for (int j = 0; j < i; j++){
                if (dp[j]) {
                    string word = s.substr(j, i-j);
                    if (std::find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};