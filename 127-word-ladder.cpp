class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());  
        queue<string> ladder;
        ladder.push(beginWord);
        int cnt = 1;
        while (!ladder.empty()){
            queue<string> ladder2 = ladder;
            while (!ladder2.empty()){
                string word = ladder2.front();
                    for (int j = 0; j < word.size(); j++){
                        string word2 = word;
                        
                        for (int k = 0; k < 26; k++){
                            if (k == word[j] - 'a') continue;
                            word2[j] = 'a' + k;
                            if (dict.find(word2) != dict.end()) {
                                ladder.push(word2);
                                dict.erase(word2);
                                if (word2 == endWord) return cnt + 1;
                                }                            
                            }
                    }
                ladder.pop();
                ladder2.pop();
            }
            cnt += 1;
        }
        return 0;
    }
};