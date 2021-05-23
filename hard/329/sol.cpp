typedef pair<int,int> pii;

// directions - up, right, down, left
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    
    bool Valid(int x, int y) {
        return (x >=0 && y >= 0 && x < m && y < n);
    }
    
    int Dfs(int x, int y, vector<vector<int>>& g) {
        if (dp[x][y]) return dp[x][y];
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!Valid(nx, ny) || g[nx][ny] <= g[x][y]) continue;
            dp[x][y] = max(dp[x][y], Dfs(nx, ny, g));
        }
        return ++dp[x][y]; // adding 1 for the current cell before returning
    }
    
    int longestIncreasingPath(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();
        dp = vector<vector<int>> (m, vector<int>(n, 0));
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, Dfs(i, j, g));
            }
        }
      
        return ans;
    }
};
