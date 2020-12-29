bool cmp (pair<int, char>&a, pair<int, char>&b){
    return a.first > b.first;
}
class Solution {
public:
    string reorganizeString(string S) {
        unordered_map <char, int> dict;
        for (auto &c: S){
            dict[c] += 1;
        }
        
        vector<pair<int, char>> pq;
        for (auto &c: dict){
            if (c.second > (S.size() + 1)/2) return ""; 
            pq.push_back({c.second, c.first});
        }
        
        sort(pq.begin(), pq.end(), cmp);
        
        string resorted;
        
        for (auto &c: pq){
            for (int i = 0; i < c.first; i++){
                resorted += c.second;
            }
        }
        
        string res; 
        
        for (int i = 0; i < (S.size() + 1) /2 ; i++){
            int j = i + (S.size() + 1) /2;
            res += resorted[i];
            if (j < S.size()) res += resorted[j];
        }
        
        return res;
    }
};