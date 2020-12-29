
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set <int> res;
        for (int i = 0; i < nums.size(); i++){
            while (nums[i] != i + 1) {
                if (nums[i] == nums[nums[i] - 1]) {res.insert(nums[i]); break;}
                else {
                    swap(nums[i], nums[nums[i] - 1]);
                    }
                }
        }
        vector<int> result (res.begin(), res.end());
        return result;
    }
};