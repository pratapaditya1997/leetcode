class Solution {
public:
    void transpose(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
    
    void reverseColumns(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n/2; j++) {
                swap(mat[i][j], mat[i][n-j-1]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& mat) {
        transpose(mat);
        reverseColumns(mat);
    }
};
