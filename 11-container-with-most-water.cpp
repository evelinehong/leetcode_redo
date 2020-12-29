class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxarea = 0;
        while (left < right){
            int length = min(height[left], height[right]);
            int bottom = right - left;
            int area = bottom * length;
            if (area > maxarea) maxarea = area;
            if (height[right] == length) right--;
            else left++;
        }
        return maxarea;
    }
};