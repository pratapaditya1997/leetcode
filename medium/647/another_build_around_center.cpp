class Solution {
public:
    int n;
    
    int CountAroundCenter(int l, int r, const string& s) {
        int ret = 0;
        while (l>=0 && r<n) {
            if (s[l] != s[r]) break;
            --l;
            ++r;
            ++ret;
        }
        return ret;
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        n = s.length();
        for (int i=0; i<n; ++i) {
            ans += CountAroundCenter(i, i, s);    // odd lenth palindromes
            ans += CountAroundCenter(i, i+1, s);  // even length palindromes
        }
        return ans;
    }
};
