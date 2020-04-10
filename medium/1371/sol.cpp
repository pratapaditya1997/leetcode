class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length(), mask = 0, ans=0;
        unordered_map<int,int> lastSeen;
        lastSeen[0] = -1;
        
        const string vow = "aeiou";
        for(int i=0; i<n; i++) {
            for(int j=0; j<5; j++) {
                if(s[i] == vow[j]) {
                    mask ^= (1<<j);
                }
            }
            if(lastSeen.find(mask) != lastSeen.end()) {
                ans = max(ans, i-lastSeen[mask]);
            } else {
                lastSeen[mask] = i;
            }
        }
        return ans;
    }
};
