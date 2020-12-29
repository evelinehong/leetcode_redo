class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        double res = 0;
        int i = 0;
        if (s.empty()) return 0;
        while (s[i] == ' ') i++;
        if (!isdigit(s[i]) && s[i]!= '-' && s[i] != '+') return 0;
        if (s[i] == '-' || s[i] == '+') {sign = s[i] == '-'? -1: 1; i++;}
        while (i < s.size()){
            if (!isdigit(s[i])) break;
            res = res * 10 + (s[i] - '0');
            i++;
        }
        if (res*sign > INT_MAX) return INT_MAX;
        else if (res*sign < INT_MIN) return INT_MIN;
        else return res*sign;
    }
};