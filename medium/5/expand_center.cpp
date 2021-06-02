class Solution {
public:
    int n, al, best;
    
    void F(int l, int r, const string& s) {
        while(l>=0 && r<n) {
            if (s[l] != s[r]) break;
            --l; ++r;
        }
        ++l; --r;
        if (l > r) return;
        if (r-l+1 > best) {
            best = r-l+1;
            al = l;
        }
    }
    
    string longestPalindrome(string s) {
        n = s.length();
        best = 0;
        
        for (int i=0; i<n; ++i) {
            F(i, i, s);
            F(i, i+1, s);
        }
        
        return s.substr(al, best);
    }
};
