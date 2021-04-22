int match(string a, string b) {
    int cnt = 0;
    for (int i=0; i<6; i++) {
        if (a[i] == b[i]) cnt++;
    }
    return cnt;
}

class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        for (int i=0; i<10; i++) {
            unordered_map<string, int> cnt;
            
            for (string word_1: words) {
                for (string word_2: words) {
                    if (match(word_1, word_2) == 0) {
                        cnt[word_1]++;
                    }
                }
            }
            
            pair<string, int> best_pick = {words[0], INT_MAX};
            for (string word: words) {
                if (cnt[word] <= best_pick.second) {
                    best_pick = {word, cnt[word]};
                }
            }
            
            int guess_match = master.guess(best_pick.first);
            vector<string> reduced_words;
            for (string word: words) {
                if (match(best_pick.first, word) == guess_match) {
                    reduced_words.push_back(word);
                }
            }
            words = reduced_words;
        }
    }
};
