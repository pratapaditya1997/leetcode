const int N = 1e4 + 4;

vector<int> g[N], cnt, stsum;

void init(int n) {
    for (int i=0; i<N; i++) {
        g[i].clear();
    }
    cnt.assign(n, 0);
    stsum.assign(n, 0);
}

void dfs(int v, int p) {
    cnt[v] = 1; 
    for (int to: g[v]) {
        if (to == p) continue;
        dfs(to, v);
        cnt[v] += cnt[to];
        stsum[v] += (stsum[to] + cnt[to]);
    }
}


void dfs2(int v, int p, int& n) {
    for (int to: g[v]) {
        if (to == p) continue;
        stsum[to] = stsum[v] - cnt[to] + n - cnt[to];
        dfs2(to, v, n);
    }
}

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        init(n);
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        dfs2(0, -1, n);
        return stsum;
    }
};
