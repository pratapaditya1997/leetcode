class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> rowCount(n,0), colCount(m,0);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] != 0) {
                    rowCount[i] += 1;
                    colCount[j] += 1;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(rowCount[i] != m || colCount[j] != n) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};
