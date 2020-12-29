class Solution {
public:
   unordered_map<char, string> letters = {{'1',""},{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    
    vector<string> letterCombinations(string digits) {
        if (digits == "") return vector<string> {};
        return letterCombinations(digits, vector<string> {""});
    }
    vector<string> letterCombinations(string digits, vector<string> result){
        if (digits == "") return result;
        vector<string> res;
        int siz = result.size();
        for (int i = 0; i < siz; i++){
            for (char &c: letters[digits[0]]){
                res.push_back(result.back() + c);
            }
            result.pop_back();
            
        }
        return letterCombinations(digits.substr(1), res);
    }
};