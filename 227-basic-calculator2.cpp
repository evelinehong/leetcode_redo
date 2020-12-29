class Solution {
public:
    vector<char> op_stack;
    vector<int> num_stack;
    unordered_map <char, int> priority {{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
    
    int calculate(string s) {
        int number = 0;
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
                op_stack.push_back(s[i]);
            }
        }
        while (!op_stack.empty()) {
            operation();
        }
        return num_stack.back();
    }
    
    void operation (){
        char op = op_stack.back();
        op_stack.pop_back();
        int num2 = num_stack.back();
        num_stack.pop_back();
        int num1 = num_stack.back();
        num_stack.pop_back();
        if (op == '*') num_stack.push_back(num1 * num2);
        else if (op == '/') num_stack.push_back((int) num1 / num2);
        else if (op == '+') num_stack.push_back(num1 + num2);
        else if (op == '-') num_stack.push_back(num1 - num2);
    }
};