class Solution {
public:
    vector<int> dx = {-1,-1,-1,0,0,1,1,1};
    vector<int> dy = {-1,0,1,-1,1,-1,0,1};
    
    void gameOfLife(vector<vector<int>>& mat) {
        int n = (int)mat.size(), m = (int)mat[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int new_i, new_j, liveCount = 0;
                for(int k=0; k<8; k++) {
                    new_i = i + dx[k];
                    new_j = j + dy[k];
                    if(!(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m)) continue;
                    if(mat[new_i][new_j] == 1 || mat[new_i][new_j] == 2) {
                        liveCount++;
                    }
                }
                if(mat[i][j] == 0 && liveCount == 3) mat[i][j] = 3;
                if(mat[i][j] == 1 && (liveCount < 2 || liveCount > 3)) mat[i][j] = 2;
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 2) mat[i][j] = 0;
                if(mat[i][j] == 3) mat[i][j] = 1;
            }
        }
    }
};
