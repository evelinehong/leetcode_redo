class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> dict ;
        for (int i = 0; i < nums.size(); i++){
            dict.insert(nums[i]);
        }
        int maximum = 0;
        
        for (auto &d: nums){
            if (dict.find(d) == dict.end()) continue;
            dict.erase(d);
            int left = d, right = d;
            
            while (dict.find(left - 1) != dict.end()) {left--; dict.erase(left);}
            while (dict.find(right + 1) != dict.end()) {right++; dict.erase(right);}
            maximum = max(maximum, right - left + 1);
        }
        return maximum;
    }
};