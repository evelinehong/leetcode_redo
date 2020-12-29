class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mapping (26);
        for (int i = 0; i < order.size(); i++){
            mapping[order[i]-'a'] = i;
        }
        vector<string> new_words;
        for (auto &w: words){
            string new_word = "";
            for (auto &a: w){
                new_word += mapping[a-'a'];
            }
             new_words.push_back(new_word);
        }
        return is_sorted (new_words.begin(), new_words.end());
    }
};