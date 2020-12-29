class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        // initialize a vector is important;
        vector<string> path;
        partition (s, 0,  path);
        return res;
    }
    
    void partition (string &s, int idx, vector<string> &path){
        if (idx == s.size()) res.push_back(path);
        for (int j = idx; j < s.size(); j++){
            if (palindrome (s, idx, j)) {
                path.push_back(s.substr(idx, (j - idx + 1)));
                partition (s, j + 1, path);
                path.pop_back();
            } 
        }
    }
    
    bool palindrome (string s, int left, int right){
        while (s[left] == s[right] && left < right){
            left++;
            if (left == right) break;
            right--;
        } 
        return (left == right);
    }
    
};