const int N = 2005;

const int WHITE = 1;
const int GRAY = 2;
const int BLACK = 3;

vector<int> g[N];
vector<int> col;
bool possible = true;

void init(int n) {
    for (int i=0; i<N; i++) g[i].clear();
    col.assign(n, WHITE);
    possible = true;
}

void dfs(int v, vector<int>& ans) {
    col[v] = GRAY;
    for (int to: g[v]) {
        if (col[to] == WHITE) dfs(to, ans);
        else if (col[to] == GRAY) {
            possible = false;
            return;
        }
    }
    col[v] = BLACK;
    ans.push_back(v);
}

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        init(n);
        
        for (auto& edge: edges) {
            int x = edge[0], y = edge[1];
            g[y].push_back(x);
        }
        
        vector<int> ans;
        for (int i=0; i<n; i++) {
            if (col[i] == WHITE) dfs(i, ans);
        }
        
        reverse(ans.begin(), ans.end());
        if (!possible) ans.clear();
        return ans;
    }
};
