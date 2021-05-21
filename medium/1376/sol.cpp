typedef pair<int, int> pii;

class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) {
        vector<pii> g[n];
        
        for (int i=0; i<n; i++) {
            if (i == headId) continue;
            int mgr = manager[i];
            g[mgr].push_back({i, informTime[mgr]});
        }
        
        queue<pii> q;
        q.push({headId, 0});
        int ans = 0;
        
        while (!q.empty()) {
            int v = q.front().first;
            int time = q.front().second;
            q.pop();
            
            for (pii& p: g[v]) {
                int to = p.first, w = p.second;
                ans = max(ans, time + w);
                q.push({to, time + w});
            }
        }
        
        return ans;
    }
};
