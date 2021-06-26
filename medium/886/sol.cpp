vector<vector<int>> g;
vector<int> col;

bool ans;

void Dfs(int v) {
    for (int to: g[v]) {
        if (col[to] != -1 && col[to] == col[v]) {
            ans = false;
            return;
        }
        if (col[to] == -1) {
            col[to] = 1 - col[v];
            Dfs(to);
        }
    }
}

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        g = vector<vector<int>> (n+1, vector<int>());
        col = vector<int> (n+1, -1);
        
        for (auto edge: edges) {
            int u = edge[0], v= edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        ans = true;
        for (int i=1; i<=n; ++i) {
            if (col[i] == -1) {
                col[i] = 0;
                Dfs(i);
                if (!ans) return false;
            }
        }
        
        return ans;
    }
};
