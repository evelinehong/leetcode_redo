class Solution {
public:
    vector<int> dict;
    Solution(vector<int>& w) {
        int num = 0;
        for (int i = 0; i < w.size(); i++){
            num += w[i];
            dict.push_back(num);
        }
    }
    
    int pickIndex() {
        int random = rand() % dict.back();
        auto it = upper_bound(dict.begin(), dict.end(), random);
        return it-dict.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */