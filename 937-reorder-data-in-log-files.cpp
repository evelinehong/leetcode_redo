struct node{
        string first,second;
        int cnt;
        bool operator < (const node & b) const {
const char x = second[0], y = b.second[0];
        if (isdigit(x) && isalpha(y)) return 0;
        if (isalpha(x) && isdigit(y)) return 1;
        if (isalpha(x) && isalpha(y)) return second == b.second ? first < b.first : second < b.second;
        return cnt < b.cnt;
        }
    };

class Solution {
public:
    
    int helper(string & str){
        int res = -1;
        for(int i = 0; i< str.size(); i++){
            if (str[i] == ' ') return res = i;
        }
        return -1;
    }
    
    
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<node> v;
        const int N = logs.size();
        int cnt = 0;
        for(auto & str : logs){
            const int res = helper(str);
            v.push_back({str.substr(0,res), str.substr(res+1),++cnt});
        }
        sort(v.begin(), v.end());
        vector<string> res;
        for(auto & cur: v){
            res.push_back(cur.first + ' ' +cur.second);
        }
        return res;
    }
};