const int N = 2005;

vector<int> g[N];
vector<int> vis;

void init(int n) {
    for (int i=0; i<N; i++) g[i].clear();
    vis.assign(n, 0);
}

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        init(n);
        
        vector<int> in_deg(n, 0);
        for (auto& edge: edges) {
            int x = edge[0], y = edge[1];
            in_deg[x]++;
            g[y].push_back(x);
        }
        
        queue<int> q;
        vector<int> ans;
        for (int i=0; i<n; i++) {
            if (in_deg[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int v = q.front(); q.pop();
            ans.push_back(v);
            vis[v] = 1;
            
            for (int to: g[v]) {
                in_deg[to]--;
                if (in_deg[to] == 0) q.push(to);
            }
        }
        
        if (*min_element(vis.begin(), vis.end()) == 0) ans.clear();
        return ans;
    }
};
