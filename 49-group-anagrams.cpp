class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> dict;
        vector<vector<string>> res;
        for (string &s: strs){
            string s0 = s;
            sort (s.begin(), s.end());
            dict[s].push_back(s0);
        }
        for (auto &v: dict){
            res.push_back(v.second);
        }
        return res;
    }
};