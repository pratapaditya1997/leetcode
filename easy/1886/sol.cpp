class Solution {
public:
    int n, m;
    
    void Transpose(vector<vector<int>>& mat) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                int tmp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = tmp;
            }
        }
    }
    
    void Mirror(vector<vector<int>>& mat) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m/2; ++j) {
                int tmp = mat[i][j];
                mat[i][j] = mat[i][n-1-j];
                mat[i][n-1-j] = tmp; 
            }
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();
        m = mat[0].size();
        
        for (int r=0; r<4; ++r) {
            Transpose(mat);
            Mirror(mat);
            if (mat == target) return true;
        }
        return false;
    }
};
