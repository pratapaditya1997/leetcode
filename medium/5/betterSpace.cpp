class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), ans = 0;
        if(n == 0) return "";
        
        int l=0;
        for(int i=0; i<n; i++) {
            int len = max(expand(i,i,s), expand(i,i+1,s));
            if(len >= ans) {
                l = i - (len-1)/2;
                ans = len;
            }
        }
        return s.substr(l,ans);
    }
    
    int expand(int l, int r, string& s) {
        int n = s.length();
        while(l>=0 && r<n && s[l] == s[r]) {
            l--;
            r++;
        }
        return r-l-1;
    }
};
