class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    
    int n,m;
    
    void dfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = '0';
        for(int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == '1') {
                dfs(nx, ny, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if(n == 0) return 0;
        
        m = grid[0].size();
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};
