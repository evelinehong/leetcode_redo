class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        // vector<int> dp (nums.size(), 1);
        // int res = 1;
        // for (int i = 1; i < nums.size(); i++){
        //     for (int j = i - 1; j >= 0; j--){
        //         if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        //         res = max(res, dp[i]);
        //     }
        // }
        // return res;
        
        vector<int> res;
        res.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++){
            auto it = lower_bound (res.begin(), res.end(), nums[i]);
            if (it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();

};