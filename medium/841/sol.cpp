class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if(vis[cur]) continue;
            vis[cur] = 1;
            for(int key: rooms[cur]) {
                if(!vis[key]) q.push(key);
            }
        }
        
        for(int i=0; i<n; i++) if(!vis[i]) return false;
        return true;
    }
};
