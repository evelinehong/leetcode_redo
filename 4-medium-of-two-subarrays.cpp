//we want nums2[mid2] < nums1[mid+1]; nums1[mid] < nums2[mid+1];
//vector. insert to the front
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            swap (nums1, nums2);
        }
        
        nums1.insert(nums1.begin(), -0x3f3f3f3f);
        nums1.push_back(0x3f3f3f3f);
        for (int i = 0; i < (nums1.size() - nums2.size())/2; i++){
            nums2.insert(nums2.begin(), -0x3f3f3f3f);
            nums2.push_back(0x3f3f3f3f);
        }
        int m = nums1.size(), n = nums2.size();
        
        int left = 0, right = m - 1, mid, mid2;
        while (left < right){
            mid = (left + right) / 2;
            mid2 = (m + n) / 2 - mid - 2;
            
            if ((nums1[mid] > nums2[mid2+1])) right = mid; 
            else if ((nums2[mid2] > nums1[mid+1])) left = mid + 1;
            else {
                if ((m + n) % 2 == 0) {
                    // if (mid2 >= n - 1) return (double) (nums1[(m-mid2-3)] + nums1[(m-mid2-4)]) / 2;
                    return (double) (max(nums1[mid], nums2[mid2]) + min(nums1[mid+1], nums2[mid2+1])) / 2;
                }
                else {
                    // if (mid2 >= n - 1) return (double) nums1[(m-mid2-2)] / 2;
                    // if (mid2 == 0x3f3f3f3f) return (double) (nums1[(n-m-1)] + nums1[(n-m-2)]) / 2;-
                    return min(nums1[mid+1], nums2[mid2+1]);
                }
            }
        }
        return 0;
    }
};