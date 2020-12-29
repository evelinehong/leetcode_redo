struct node{
    int val;
    int feq;
};
bool cmp(node &a, node &b){
    return a.feq >= b.feq;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        vector<node> sorted;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            dict[nums[i]]++;
        }
        for (auto&d: dict){
            sorted.push_back({d.first, d.second});
        }
        partial_sort(sorted.begin(), sorted.end(), sorted.begin()+k, cmp);
        for (int i = 0; i < k; i++){
            res.push_back(sorted[i].val);
        }
        return res;
    }
};