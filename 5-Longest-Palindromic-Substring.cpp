class Solution {
public:
    string longestPalindrome(string s) {
        int left, right, maxlen = 1, maxleft = 0;
        for (int i = 0; i < s.size(); i++){
            left = right = i;
            while (right < s.size() - 1 && s[right] == s[right+1]){
                right ++;
            }
            while (s[left] == s[right]){
                if ((right - left + 1) > maxlen){
                    maxlen = right - left + 1;
                    maxleft = left;
                }
                if (left > 0 && right < s.size() - 1){
                left--;
                right++;
                }
                else break;
            }
        }
        return s.substr(maxleft, maxlen);
    }
};