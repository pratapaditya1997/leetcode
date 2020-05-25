class Solution {
public:
    int maxVowels(string s, int k) {
        const string vowel = "aeiou";
        auto isVowel = [&vowel](char c) {
            return (vowel.find(c) != string::npos);
        };
        
        int ans = 0, cur = 0, n = s.length();
        for(int i=0; i<k; i++) if(isVowel(s[i])) cur++;
        ans = cur;
        for(int i=k; i<n; i++) {
            if(isVowel(s[i])) cur++;
            if(isVowel(s[i-k])) cur--;
            ans = max(ans, cur);
        }
        
        return ans;
    }
};
