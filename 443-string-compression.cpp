class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;
        int ptr = 0;
        
        for (int i = 0; i < chars.size(); i++){
            chars[ptr] = chars[i];
            int cnt = 1;
            while (i < chars.size() - 1 && chars[i+1] == chars[i]) {
                i++;
                cnt++;
            }
            if (cnt == 1) ptr += 1;
            else {
                string count = to_string(cnt);
                for (char &c: count){
                    ptr += 1;
                    chars[ptr] = c;
                }
                ptr += 1;
            }
        }
        chars.resize(ptr);
        return chars.size();
    }
};