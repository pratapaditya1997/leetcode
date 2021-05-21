typedef pair<int, int> pii;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char dir[4] = {'L','R','U','D'};

bool valid(int x, int y, vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size();
    return (x >= 0 && y >= 0 && x < n && y < m && g[x][y]);
}

void dfs(int x, int y, vector<vector<int>>& g, string& cur) {
    g[x][y] = 0;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny, g)) {
            cur += dir[i];
            dfs(nx, ny, g, cur);
        }
    }
    cur += '0';
}

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        unordered_set<string> ans;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (g[i][j]) {
                    string cur = "";
                    dfs(i, j, g, cur);
                    ans.insert(cur);
                }
            }
        }
        
        return ans.size();
    }
};
