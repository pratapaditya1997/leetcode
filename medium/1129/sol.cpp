const int N = 105;

vector<int> red[N], blue[N];

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        for(int i=0; i<N; i++) {
            red[i].clear();
            blue[i].clear();
        }
        
        vector<vector<int>> dist(n, vector<int>(2, -1));
        
        for(auto v: red_edges) red[v[0]].push_back(v[1]);
        for(auto v: blue_edges) blue[v[0]].push_back(v[1]);
        
        queue<pair<int,int>> q;
        q.push({0,0}); dist[0][0] = 0;
        q.push({0,1}); dist[0][1] = 0;
        while(!q.empty()) {
            int node = q.front().first, col = q.front().second;
            q.pop();
            if(col) {
                for(int v: red[node]) {
                    if(dist[v][1-col] == -1) {
                        dist[v][1-col] = dist[node][col] + 1;
                        q.push({v, 1-col});
                    }
                }
            } else {
                for(int v: blue[node]) {
                    if(dist[v][1-col] == -1) {
                        dist[v][1-col] = dist[node][col] + 1;
                        q.push({v, 1-col});
                    }
                }
            }
        }
        
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++) {
            if(dist[i][0] == -1 && dist[i][1] == -1) ans[i] = -1;
            else if(dist[i][0] == -1) ans[i] = dist[i][1];
            else if(dist[i][1] == -1) ans[i] = dist[i][0];
            else ans[i] = min(dist[i][0], dist[i][1]);
        }
        return ans;
    }
};
