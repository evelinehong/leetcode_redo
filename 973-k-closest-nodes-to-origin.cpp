bool cmp (vector<int> &a, vector<int> &b){
    return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin()+K, points.end(), cmp);
        points.resize(K);
        return points;
    }
};