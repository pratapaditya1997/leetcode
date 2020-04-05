class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length(), m = s.length();
        int i=0,j=0;
        while(i<n && j<m) {
            if(t[i] == s[j]) {
                j++;
            }
            i++;
        }
        return (j == m);
    }
};
