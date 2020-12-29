struct node{
    string word;
    int freq;
};
bool cmp(node &a, node &b){
    if (a.freq == b.freq) return a.word < b.word;
    else return a.freq > b.freq;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map <string, int> mymap;
        for (auto &str: words){
            mymap[str] += 1;
        }
        vector<node> sorted_map; 

        for (auto &str: mymap) { 
            sorted_map.push_back({str.first, str.second}); 
        } 
        
        partial_sort(sorted_map.begin(), sorted_map.begin()+k, sorted_map.end(), cmp);
        sorted_map.resize(k);
        
        vector<string> res;
        
        for (auto &n: sorted_map){
            res.push_back(n.word);
        }
        return res;
    }
};