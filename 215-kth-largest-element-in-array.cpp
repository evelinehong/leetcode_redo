class Solution {
public:
    int quicksort(vector<int> & nums, int start,int end){
        int pivot = nums[start], left=  start + 1, right = end;
        while(left <= right){
            if (nums[left] >= pivot) left++;
            else if (nums[right] <= pivot) right--;
            else swap(nums[left], nums[right]), left++;
        }
        swap(nums[start],nums[right]);
        return right;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        /*
        priority_queue<int> sorted;
        for (int i = 0; i < nums.size(); i++){
            sorted.push(nums[i]);
        }
        for (int i = k - 1; i > 0; i--) sorted.pop();
        return sorted.top();
        */
        k--;
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int res = quicksort(nums, low,high);
            if (res == k) return nums[res];
            if (res <  k) low = res + 1;
            else high = res - 1;
        }
        return 0;
    }
};