class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26,0);
        for(char c: s) {
            count[c-'a']++;
        }
        for(char c: t) {
            count[c-'a']--;
        }
        
        int ans = 0;
        for(int i=0; i<26; i++) ans += abs(count[i]);
        return ans/2;
    }
};
