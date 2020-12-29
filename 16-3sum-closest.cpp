class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = -0x3f3f3f3f;
        sort (nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++){
            int left = i + 1, right = nums.size() - 1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) return target;
                if (abs (sum - target) < abs (closest - target)) closest = sum;
                if (sum < target) left++;
                else right--;
            }
        }
        return closest;
    }
};