class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (find (nums.begin(), nums.end(), target) == nums.end()) return vector<int> {-1,-1};
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        int idx1 = it1 - nums.begin();
        int idx2 = it2 - 1 - nums.begin();
        return vector<int> {idx1, idx2};
    }
};