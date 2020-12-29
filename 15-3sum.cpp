class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        nums.insert (nums.begin(), 3, -0x3f3f3f3f);
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 3; i < nums.size() - 2; i++){
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right){
                if (nums[left] + nums[right] < target) left++;
                else if (nums[left] + nums[right] > target) right--;
                else {res.push_back({nums[i], nums[left], nums[right]}); 
                      while (left < nums.size() - 1 && nums[left] == nums[left+1]) left++;
                      while (right > 0 && nums[right] == nums[right-1]) right--;
                      left++; 
                      right--;}
            }
            while (i < nums.size() - 1 && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};