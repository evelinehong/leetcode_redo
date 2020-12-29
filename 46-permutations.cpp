class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> permute(vector<int>& nums) {
        permute (nums, 0);    
        return res;
    }
    
    void permute (vector<int> &nums, int idx){
        if (idx == nums.size()) res.push_back(nums); 
        for (int j = idx; j < nums.size(); j++){
            swap (nums[idx], nums[j]);
            permute (nums, idx + 1);
            swap (nums[j], nums[idx]);
            }
    }
    
};