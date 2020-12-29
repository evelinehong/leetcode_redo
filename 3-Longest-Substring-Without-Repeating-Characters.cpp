class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map <char, int> idx;
        int max_len = 1;
        int prev = 1;
        idx[s[0]] = 1;
        for (int i = 1; i < s.size(); i++){
            int length = min (i + 1 - idx[s[i]], prev + 1);
            prev = length;
            if (length > max_len) max_len = length;
            idx[s[i]] = i + 1;
        }
        return max_len;
    }
};