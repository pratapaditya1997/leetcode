class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> g[n];
        vector<int> in_deg(n,0), safe(n,0);
        queue<int> q;
        
        for(int i=0; i<n; i++) {
            auto v = graph[i];
            for(int j: v) {
                g[j].push_back(i);
                in_deg[i]++;
            }
            if(in_deg[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int u = q.front(); q.pop();
            safe[u] = 1;
            for(int v: g[u]) {
                in_deg[v]--;
                if(in_deg[v] == 0) q.push(v);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++) if(safe[i]) ans.push_back(i);
        return ans;
    }
};
