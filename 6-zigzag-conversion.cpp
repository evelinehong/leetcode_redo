class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> arr (numRows, "");
        int step = -1, idx = 0;
        string res = "";
        for (int i = 0; i < s.size(); i++){
            if (i % (numRows - 1) == 0) step = -1 * step;
            arr[idx] += s[i];
            idx += step;
        }
        for (int i = 0; i < numRows; i++){
            res += arr[i];
        }
        return res;
    }
};