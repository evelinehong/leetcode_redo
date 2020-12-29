
// The trick is to use monotone increasing queue. When you have a input heights[0],heights[1]...,heights[i],...heights[n-1] which is monotone increasing queue,things become simple:
// n-1 is the right side of rectangle, all the n-2 to 0 may possibly be the left side, so you need to compare all the heights[i]*(n-1-i).
// Now let's suppose we have calculated the max area when right side of rectangle reaches n-1, and what happened when we have a new heights[n]:
// a.
// if heights[n] >= all previous heights, then move right side from n-1 to n is always a better choice
// b.
// if heights[n] < heights[i], i is somewhere between 0 to n-1, then moving right side from n-1 to n is always a better choice for cases of left side<i, so better calculate these later.(keep possible left indexes in stack)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //sentinel node
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        vector<int> mstack;
        mstack.push_back(0);
        int area = 0;
        
        for (int i = 1; i < heights.size(); i++){
            while (heights[mstack.back()] > heights[i]){
                int height = heights[mstack.back()];
                mstack.pop_back();
                //prev is what's left in stack is the rightmost idx with height smaller than heights[i]; so we take the rectangle to its right;
                //just think about what's left in the stack. It's a ladder. if there's higher block in between that's not in index, it donesn't matter because their heights have been previously considered, and doesn't count any more since other blocks limit the height,
                int prev = mstack.back();
                // i - 1 is the right of the rectangle. which is the highest in stack. prev + 1 is the left of the rectangle considered so far.
                int length = i - 1 - (prev + 1) + 1;
                area = max(area, height * length);
            }
            mstack.push_back(i);
        }
        return area;
    }
};