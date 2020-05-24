class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length();
        int m = searchWord.length();
        
        int ans = 1;
        for(int i=0; i <= n-m; i++) {
            if(i == 0 || sentence[i-1] == ' ') {
                if(sentence.substr(i,m) == searchWord) return ans;
            }
            if(sentence[i] == ' ') ans++;
        }
        return -1;
    }
};
