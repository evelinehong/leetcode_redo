bool cmp (vector<int>& a, vector<int>&b) {
    return a[0]<b[0];
}
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int> prev;
        if (!intervals.empty()) prev = intervals[0];
        vector<vector<int>> res;
        if (!prev.empty()) res.push_back(prev);
        for (int i = 1; i < intervals.size(); i++){
            vector<int> interval = intervals[i];
            if (interval[0] <= prev[1]){
                prev[1] = max(prev[1], interval[1]);
                res.pop_back();
            }
            else prev = interval;
            res.push_back(prev);
        }
        return res;
    }
};