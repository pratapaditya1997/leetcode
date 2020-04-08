class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> hor(n, vector<int>(m,0)), ver(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]) {
                    hor[i][j] = (j>0) ? hor[i][j-1]+1 : 1;
                    ver[i][j] = (i>0) ? ver[i-1][j]+1 : 1;
                }
            }
        }
        
        int best = 0;
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int lim = min(hor[i][j], ver[i][j]);
                for(int k=lim; k>=1 && k>best; k--) {
                    if(hor[i-k+1][j] >= k && ver[i][j-k+1] >= k) {
                        best = max(best, k);
                    }
                }
            }
        }
        return best*best;
    }
};
