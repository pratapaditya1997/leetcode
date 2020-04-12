class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        int ans = n, k = n/4, l = 0,r = 0;
        
        unordered_map<char,int> m = {{'Q',0},{'W',1},{'E',2},{'R',3}};
        vector<int> count(4,0);
        
        for(char c: s) count[m[c]]++;
        while(r<n) {
            count[m[s[r]]]--;
            r++;
            while(l<n && max({count[m['Q']], count[m['W']], count[m['E']], count[m['R']]}) <= k) {
                ans = min(ans, r-l);
                count[m[s[l]]]++;
                l++;
            }
        }
        return ans;
    }
};
