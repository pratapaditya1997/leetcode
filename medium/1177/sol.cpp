class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length(), m = queries.size();
        vector<bool> ans(m, false);
        vector<vector<int>> preSum(n+1, vector<int>(26,0));
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<26; j++) preSum[i][j] = preSum[i-1][j];
            preSum[i][s[i-1]-'a']++;
        }
        
        for(int i=0; i<m; i++) {
            int l=queries[i][0], r=queries[i][1], k=queries[i][2];
            int len = r-l+1;
            if(k >= len/2) {
                ans[i] = true;
            } else {
                int odd=0;
                for(int j=0; j<26; j++) {
                    if((preSum[r+1][j]-preSum[l][j])&1) odd++;
                }
                if(k >= odd/2) ans[i] = true;
            }
        }
        
        return ans;
    }
};
