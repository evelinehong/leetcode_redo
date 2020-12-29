class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right){
            int mid = (left + right) / 2;
            if (nums[right] < nums[mid]) left = mid + 1;
            else right = mid;
        }
        int cut = left;
        
        int nleft = cut, nright = cut + n - 1;
        while (nleft < nright) {
            int mid = (nleft + nright) / 2;
            int nmid = mid % n;
            if (nums[nmid] == target) return nmid;
            if (nums[nmid] < target) nleft = mid + 1;
            else nright = mid - 1;
        }
        nleft = (nleft + n) % n;
        if (nums[nleft] == target) return nleft;
        return -1;
    }
};