class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mymap;
        for (int i = 0; i < nums.size(); i++){
            if (mymap[target - nums[i]] != 0) return vector<int> {mymap[target - nums[i]] - 1, i};
            mymap[nums[i]] = i+1;
        }
        return vector<int> {};
    }
};