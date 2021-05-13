class dsu {
public:
    vector<int> p,sz;
    int n;
    
    dsu(int _n): n(_n) {
        p.resize(n);
        sz.resize(n);
        iota(p.begin(), p.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }
    
    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    
    inline int unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if (sz[x] < sz[y]) {
                swap(x, y);
            }
            p[y] = x;
            sz[x] += sz[y];
            return sz[x];
        }
        return -1; 
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n; 
        
        dsu d(n);
        int ans = 1;
        unordered_map<int, int> m;
        
        for (int i=0; i<n; i++) {
            int num = nums[i];
            if (m.find(num) != m.end()) continue;
            m[num] = i;
            
            if (m.find(num - 1) != m.end()) {
                ans = max(ans, d.unite(i, m[num - 1]));
            }
            if (m.find(num + 1) != m.end()) {
                ans = max(ans, d.unite(i, m[num + 1]));
            }
        }
        
        return ans;
    }
};
