//swap can only be used nums[i], nums[j];
//upper_bound used on sorted array;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int left = 0, right = nums.size() - 1, ptr = nums.size() - 1;
        
        while (ptr > 0 && nums[ptr] <= nums[ptr - 1]){
            ptr--;
        }
        ptr--;
        if (ptr>=0) 
        {  sort (nums.begin() + ptr + 1, nums.end());
           auto it = upper_bound(nums.begin()+ptr, nums.end(), nums[ptr]);
            swap(nums[ptr], nums[it - nums.begin()]);
        }
        else sort (nums.begin(), nums.end());

    }
};