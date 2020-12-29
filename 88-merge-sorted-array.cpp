//!i is 0! do not use !i.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (i >= 0 && j >= 0){
            if ( nums1[i] > nums2[j]){
                nums1[last] = nums1[i];
                i--;
            }
            else {
                nums1[last] = nums2[j];
                j--;
            }
            last--;
        }  
        if (i < 0) {
            for (int cnt = j; cnt >= 0; cnt--){
                nums1[last] = nums2[cnt];
                last--;
            }
        }
    }
};