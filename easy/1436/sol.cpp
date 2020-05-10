class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int> out;
        for(auto v: paths) {
            if(out.find(v[0]) == out.end()) {
                out[v[0]] = 1;
            } else out[v[0]]++;
            if(out.find(v[1]) == out.end()) {
                out[v[1]] = 0;
            }
        }
        
        for(auto p: out) {
            if(p.second == 0) return p.first;
        }
        return "";
    }
};
