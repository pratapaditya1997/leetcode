class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> sum(n+1, vector<int>(m+1,0));
        vector<vector<int>> ans(n, vector<int>(m,0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                sum[i][j] = mat[i-1][j-1];
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        
        auto sumBetween = [&sum](int p,int q,int r, int s) {
            return sum[r][s] - sum[r][q-1] - sum[p-1][s] + sum[p-1][q-1];
        };
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int p = max(i-K,0)+1, q = max(j-K,0)+1;
                int r = min(i+K,n-1)+1, s = min(j+K,m-1)+1;
                ans[i][j] = sumBetween(p,q,r,s);
            }
        }
        return ans;
    }
};
