class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> prevDp(m+1,0), curDp(m+1,0);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) {
                    curDp[j] = prevDp[j-1]+1;
                } else {
                    curDp[j] = max(prevDp[j], curDp[j-1]);
                }
            }
            for(int j=0; j<=m; j++) {
                prevDp[j] = curDp[j];
                curDp[j]=0;
            }
        }
        return prevDp[m];
    }
};
