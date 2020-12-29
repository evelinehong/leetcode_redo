class Solution {
public:
    string decodeString(string s) {
        vector<int> stack_num;
        vector<string> stack_string;
        stack_num.push_back(1);
        stack_string.push_back("");
        int num = 0;
        for (auto &c: s){
            if (isalpha(c)) stack_string.back() += c;
            else if (isdigit(c)) num = num*10 + c - '0';
            else if (c == '[') {
                stack_num.push_back(num);
                num = 0;
                stack_string.push_back("");
            }
            else if (c ==']') {
                string old_string = stack_string.back();
                stack_string.pop_back();
                for (int i = 0; i < stack_num.back(); i++) {
                    stack_string.back() += old_string;
                }                
                stack_num.pop_back();
            }
        }
        return stack_string[0];
    }
};