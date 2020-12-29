class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size() - 1, n = num2.size() - 1, carry = 0;
        string res;
        while (m >= 0|| n >= 0 || carry){
            int sum = carry;
            if (m >= 0) sum += num1[m] - '0', m--;
            if (n >= 0) sum += num2[n] - '0', n--;
            carry = sum / 10;
            char s = sum % 10 + '0';
            res = s + res;
        }
        return res;
    }
};