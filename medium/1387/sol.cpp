static map<int,int> m;

class Solution {
public:
    vector<pair<int,int>> v;
    
    int dfs(int n) {
        if(n == 1) return 0;
        if(m.find(n) != m.end()) return m[n];
        
        int ret;
        if(n&1) ret =  1 + dfs(3*n+1);
        else ret =  1 + dfs(n/2);
        m[n] = ret;
        return ret;
    }
    
    int getKth(int lo, int hi, int k) {
        for(int i=lo; i<=hi; i++) {
            v.push_back({dfs(i),i});
        }
        sort(v.begin(), v.end());
        return v[k-1].second;
    }
};
