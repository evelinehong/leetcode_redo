
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map <string, map<long, string>> dict;
        unordered_map <string, int> sequence;
        for (int i = 0; i < username.size(); i++){
            dict[username[i]][timestamp[i]] = website[i];
        }
        
        vector<string> res;
        int cnt = 0;
        
        for (auto &d: dict){
            if (d.second.size() < 3) continue;
            vector<string> copy= {};
            unordered_set <string> count;
            for (auto &s: d.second){
                copy.push_back(s.second);
            }
            
            for (int i = 0; i < copy.size() - 2; i++){
                for (int j = i + 1; j < copy.size() - 1; j++){
                    for (int k = j + 1; k < copy.size(); k++){
                        string se = copy[i] + ";" + copy[j] + ";" + copy[k];
                        if (count.find(se) != count.end()) continue; 
                        vector<string> seq = {copy[i], copy[j], copy[k]};
                        count.insert (se);
                        sequence[se] += 1;
                        if (sequence[se] > cnt || (sequence[se] == cnt && seq < res)) {res = seq; cnt = sequence[se];}
                    }
                }
            }
            
        } 
    
        return res;
    }
};