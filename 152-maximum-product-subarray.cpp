class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int inf = 0x3f3f3f3f;
        int minn = nums[0], maxx = nums[0],res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int val = nums[i];
            int tmp1 = minn * val,tmp2 = maxx * val;
            maxx = std::max(tmp1,std::max(tmp2,val));
            minn = std::min(tmp1,std::min(tmp2,val));
            res = std::max(maxx,res);
        }
        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // vector<int> dp (nums.size(), 0);
        // vector<int> dp2 (nums.size(), 0);
        int dp = nums[0] > 0? nums[0]: 0;
        int dp2= nums[0] < 0? nums[0]: 0;
        
        int resmax = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                dp = (dp < 1)? nums[i]: dp * nums[i];
                dp2 = dp2*nums[i];
            }
            else if (nums[i] < 0) {
                int tmp = dp;
                dp = dp2 * nums[i];
                dp2 = (tmp < 1)? nums[i]: tmp * nums[i];
            }
            else {dp = 0; dp2 = 0;}
            
            if (dp > 0) resmax = max(resmax, dp);
            else resmax = max(resmax, dp2);
        }
        return resmax;
    }
};