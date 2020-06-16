const int INF = 1e7;

class Solution {
public:
    int minSumOfLengths(vector<int>& a, int k) {
        int n = size(a);
        vector<int> pre(n, INF), suf(n, INF);
        
        unordered_map<int,int> pos;
        pos[0] = -1;
        int cur = 0;
        for(int i=0; i<n; i++) {
            cur += a[i];
            if(pos.find(cur-k) != pos.end()) {
                pre[i] = min(pre[i], i-pos[cur-k]);
            }
            if(i) pre[i] = min(pre[i-1], pre[i]);
            pos[cur] = i;
        }
        
        pos.clear();
        pos[0] = n;
        cur = 0;
        for(int i=n-1; i>=0; i--) {
            cur += a[i];
            if(pos.find(cur-k) != pos.end()) {
                suf[i] = min(suf[i], pos[cur-k]-i);
            }
            if(i < n-1) suf[i] = min(suf[i+1], suf[i]);
            pos[cur] = i;
        }
        
        int ans = INF;
        for(int i=0; i<n-1; i++) {
            ans = min(ans, pre[i]+suf[i+1]);
        }
        if(ans >= INF) ans = -1;
        return ans;
    }
};
