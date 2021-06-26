vector<vector<int>> g;
vector<int> vis;

void Dfs(int v) {
    vis[v] = 1;
    for (int to: g[v]) {
        if (!vis[to]) Dfs(to);
    }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        g = vector<vector<int>> (n, vector<int>());
        vis = vector<int>(n, 0);
        
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (mat[i][j]) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        int res = 0;
        for (int i=0; i<n; ++i) {
            if (!vis[i]) {
                ++res;
                Dfs(i);
            }
        }
        
        return res;
    }
};
