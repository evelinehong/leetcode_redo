class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res (n,1);
        int fromLeft = 1, fromRight = 1;
        for (int i = 0; i < n; i++){
            int j = n - i - 1;
            res[i] *= fromLeft;
            fromLeft *= nums[i];
            res[j] *= fromRight;
            fromRight *= nums[j];
        }
        return res;
    }
};