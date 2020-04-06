class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> sum(n+1, vector<int>(m+1,0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                sum[i][j] = mat[i-1][j-1];
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        
        auto sumBetween = [&sum](int p, int q, int r, int s) {
            return sum[r][s] - sum[r][q-1] - sum[p-1][s] + sum[p-1][q-1];
        };
        
        int lim = min(n,m), ans=0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                for(int k=0; k<=lim; k++) {
                    if(i+k > n || j+k > m) break;
                    int count = sumBetween(i,j,i+k,j+k);
                    if(count == (k+1)*(k+1)) ans++;
                }
            }
        }
        return ans;
    }
};
