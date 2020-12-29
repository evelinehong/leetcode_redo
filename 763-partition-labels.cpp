class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> dict (26, -1);
        vector<int> res;
        for (int i = 0; i < S.size(); i++){
            dict[S[i]-'a'] = i;
        }
        int right = 0, left = 0; 
        for (int i = 0; i < S.size(); i++){
            right = max(right, dict[S[i]-'a']);
            if (i == right){
                res.push_back(right-left+1);
                left = i + 1;
            }
        }
        return res;
    }
};