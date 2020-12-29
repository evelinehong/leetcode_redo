class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, cnt = 0;
        unordered_map <int, int> dict;
        dict[0] = 1;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            cnt += dict[sum-k];
            dict[sum] += 1;
        }
        return cnt;
    }
};