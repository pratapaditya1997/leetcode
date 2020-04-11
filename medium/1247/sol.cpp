class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length(), xy=0, yx=0;
        
        for(int i=0; i<n; i++) {
            if(s1[i] != s2[i]) {
                if(s1[i] == 'x') xy++;
                else yx++;
            }
        }
        
        if(xy%2 != yx%2) return -1;
        int ans = xy/2+yx/2;
        if(xy%2) ans += 2;
        return ans;
    }
};
