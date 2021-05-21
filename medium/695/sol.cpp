typedef pair<int, int> pii;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool valid(int x, int y, vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size();
    return (x >= 0 && y >= 0 && x < n && y < m && g[x][y]);
}

void dfs(int x, int y, vector<vector<int>>& g, int& cur) {
    g[x][y] = 0;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny, g)) {
            cur++;
            dfs(nx, ny, g, cur);
        }
    }
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size(), ans = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (g[i][j]) {
                    int cur = 1;
                    dfs(i, j, g, cur);
                    ans = max(ans, cur);
                }
            }
        }
        
        return ans;
    }
};
