class Solution {
public:
    unordered_map <char, int> priority {{'*', 3}, {'/', 3}, {'+', 2}, {'-', 2}, {'(', 0}, {')', 1}};
    vector<char> op_stack;
    vector<int> num_stack;
    int calculate(string s) {
        
        long number = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                while (isdigit(s[i])) {
                    number = number*10 + (s[i] - '0');
                    i++;
                }
                i--;
                num_stack.push_back(number);
                number = 0;
            }
            
            if (priority[s[i]]) {
                while (!op_stack.empty() && priority[op_stack.back()] >= priority[s[i]]) {
                    operation();
                } 
                if (s[i] != ')') op_stack.push_back(s[i]);
                else op_stack.pop_back();
            }
            
            if (s[i] == '(') op_stack.push_back(s[i]);
        }
        while (!op_stack.empty()) {
            operation();
        }
        return num_stack.back();
    }
    void operation (){
        char op = op_stack.back();
        op_stack.pop_back();
        long num2 = num_stack.back();
        num_stack.pop_back();
        long num1 = num_stack.back();
        num_stack.pop_back();
        if (op == '*') num_stack.push_back(num1 * num2);
        else if (op == '/') num_stack.push_back((int) num1 / num2);
        else if (op == '+') num_stack.push_back(num1 + num2);
        else if (op == '-') num_stack.push_back(num1 - num2);
    }
};