int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        auto valid = [&](int x, int y) {
            return (x >= 0 && y >= 0 && x < n && y < m && g[x][y] == '1');
        };
        
        function<void(int, int)> dfs = [&](int x, int y) {
            vis[x][y] = 1;
            for (int i=0; i<4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (valid(nx, ny) && !vis[nx][ny]) dfs(nx, ny);
            }
        };
        
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!vis[i][j] && g[i][j] == '1') {
                    ++ans;
                    dfs(i, j);
                }
            }
        }
        
        return ans;
    }
};
