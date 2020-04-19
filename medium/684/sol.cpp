class Solution {
public:
    vector<int> p;
    
    int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if(x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
        
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        p.assign(2000,0);
        iota(p.begin(), p.end(), 0);
        for(auto edge: edges) {
            if(!unite(edge[0], edge[1])) return edge;
        }
        return edges[0];
    }
};
