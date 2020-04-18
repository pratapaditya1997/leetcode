class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(arr[u] == 0) return true;
            vis[u] = 1;
            if(u-arr[u] >= 0 && !vis[u-arr[u]]) q.push(u-arr[u]);
            if(u+arr[u] < n && !vis[u+arr[u]]) q.push(u+arr[u]);
        }
        return false;
    }
};
