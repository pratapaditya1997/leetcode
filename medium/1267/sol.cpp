class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n,0), col(m,0);
        
        for(int i=0; i<n; i++) {
            int row_sum = 0;
            for(int j=0; j<m; j++) row_sum += grid[i][j];
            if(row_sum > 1) row[i] = 1;
        }
        for(int j=0; j<m; j++) {
            int col_sum = 0;
            for(int i=0; i<n; i++) col_sum += grid[i][j];
            if(col_sum > 1) col[j] = 1;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] && (row[i] || col[j])) ans++;
            }
        }
        return ans;
    }
};
