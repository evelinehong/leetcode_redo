class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        int left = 0, right = N - 1;
        int leftmost = 0, rightmost = 0;
        int res = 0;
        while (right >= left){
            if (height[left] <= height[right]){
                if (height[left] >= leftmost) leftmost = height[left];
                else res += leftmost - height[left];
                left ++;
            }
            else {
                if (height[right] >= rightmost) rightmost = height[right];
                else res += rightmost - height[right];
                right --;
            }
        }
        return res;
    }
};